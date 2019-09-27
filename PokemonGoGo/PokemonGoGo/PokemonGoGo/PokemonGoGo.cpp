// Name: Thomas Fan		Date: 9/25/19
// Purpose: Using Dynamic Programming (dp) for Travelling Salesman Problem (tsp)

#include <iostream>
#include <algorithm>
using namespace std;
#define INT_MAX 999999

//Creating Hamiltonian Array
int Poke_Dist[10][10] = {
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};

int n = 4; //Number of Nodes
int VISITED_ALL = (1 << n) - 1;
int dp[16][4];

//TSP
//mask ex : 1  pos ex : 0
int tsp(int mask, int pos)
{
	if (mask == VISITED_ALL)
		return Poke_Dist[pos][0];
	//Now from current node, we will try to go to every other node and take the min ans
	int ans = INT_MAX;

	//Visit all the unvisited cities and take the best route
	for (int city = 0; city < n; city++)
	{
		if ((mask & (1<<city)) == 0)
		{
			int newAns = Poke_Dist[pos][city] + tsp(mask|(1<<city),city);
			ans = min(ans, newAns);
		}
	}

	return dp[mask][pos] = ans;
}
int main()
{
    //Initializing DP array
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	cout<<"The Travelling Salesman Distance Is: "<<tsp(1, 0)<<endl;
	return 0;
}

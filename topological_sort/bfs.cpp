#include<bits/stdc++.h>
using namespace std;

const int N=100001;
vector<int> graph[N];
bool vis[N];
int indegree[N];

void topoSort(int n)
{   
	memset(indegree,0,sizeof(indegree));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++)
	{
		for(int j : graph[i])
		{
			indegree[j]++;
		}
	}
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		vis[curr]=1;
		cout<<curr<<" ";
		for(int i : graph[curr])
		{
			indegree[i]--;
			if(indegree[i]==0 && !vis[i])
			{
				q.push(i);
				vis[i]=1;
			}
		}
	}


}

int main()
{
	int n,m;
	cin>>n>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		graph[x].push_back(y);
	}
	topoSort(n);

}
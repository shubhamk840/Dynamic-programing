#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;
// I hope you understand what i have coded :D , All the best
// shubhamk840@gmail.com
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
#define endl '\n'
#define stackofi stack<int>
#define queueofi queue<int>  
#define vectoriterator vector<int>::iterator
#define mapiterator map<int,int>::iterator
#define setiterator set<int>:: iterator
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define mod 1000000007
// macros for inputting 1-D and 2-D array.
#define stringiterator string:: iterator
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define ai(arr,n) for(int i=0;i<n;i++)cin>>arr[i];
#define ao(arr) for(auto wtf:arr) cout<<wtf<<" ";
#define mi(arr,m,n) for(int i=0;i<m;i++){ for(int j=0;j<n;j++) cin>>arr[i][j];}
#define mo(arr,m,n) for(int i=0;i<m;i++){ for(int j=0;j<n;j++) cout<<arr[i][j]<<" "; cout<<endl;}
#define countsetbits(x) __builtin_popcount(x)
#define ll long long
#define debugger cout<<"I AM EXECUTING"<<endl
#define F first
#define S second
#define testcases int asdf; cin>>asdf; while(asdf--)
#define space cout<<endl
#define vi vector<int>
#define si set<int>
#define vc vector<char>
#define sc set<char>


string sconvert(int n)
{
	stringstream ss;
	ss<<n;
	string str = ss.str();
	return str;
}
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second > b.second); 
}
template<typename KeyType, typename ValueType>  // for finding max element in the map.
std::pair<KeyType,ValueType> get_max( const std::map<KeyType,ValueType>& x ) {
  using pairtype=std::pair<KeyType,ValueType>; 
  return *std::max_element(x.begin(), x.end(), [] (const pairtype & p1, const pairtype & p2) {
        return p1.second < p2.second;
  }); 
}
// This is a zero one knapsack problems. //this code is working fine

int dp[1000][1000];
int ks(vector<pair<int,int>> &prs,int k,int n)
{
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			
			if(prs[j-1].first<=i) // when weight of the item is less than the k
		{
		dp[i][j]=max(prs[j-1].second+dp[i-prs[j-1].first][j-1],dp[i][j-1]);
			// considered both the choices.
		}
		else  //  when weight is grater, 
		{
	    dp[i][j]=dp[i][j-1];
	    }
	    return dp[k][n];
	}
	
   }
   return dp[k][n];
}


int main()
{
    IOS;
    testcases
    {
    vector<pair<int,int>> prs;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		prs.pb(make_pair(x,y));
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0||j==0)
			{
				dp[k][n]=0;
			}
		}
	}
	cout<<ks(prs,k,n)<<endl;
	
}
}
    
    

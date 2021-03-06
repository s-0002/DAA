TSP USING CHEAPEST LINK METHOD
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define edge pair<int,int>
 
class Graph {
private:
    vector<pair<int, edge>> G;
    vector<pair<int, edge>> T; 
    int *parent;
    int V; 
public:
    Graph(int V);
    void AddEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void TSP();
    void print();
};
Graph::Graph(int V) {
    parent = new int[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;
 
    G.clear();
    T.clear();
}
void Graph::AddEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
   
    if (i == parent[i])
        return i;
    else
        
        return find_set(parent[i]);
}
 
void Graph::union_set(int u, int v) {
    parent[u] = parent[v];
}
void Graph::TSP() {
    int i, uRep, vRep;
    sort(G.begin(), G.end()); 
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep) {
            T.push_back(G[i]); // add to tree
            union_set(uRep, vRep);
        }
    }
}
void Graph::print() {
    cout << "Edge :" << " Weight" << endl;
    int p=0;
    for (int i = 0; i < T.size(); i++) {
        p = p + T[i].first;
        cout << T[i].second.first << " - " << T[i].second.second << " : "
                << T[i].first;
        cout << endl;
    }
    cout << p;
}
int main() {
    int n , u , v , w, e;
    cin >> e; //number of edges
    cout << e;
    cin >> n; //number of vertices
    cout << n;
    Graph g(n);
       for (int i=1;i<=e;i++)
       {
         cin >> u >> v >>w;
         g.AddEdge(u,v,w);
        }
    g.TSP();
    g.print();
    return 0;
}









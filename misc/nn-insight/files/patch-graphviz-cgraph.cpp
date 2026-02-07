--- graphviz-cgraph.cpp.orig	2024-10-13 18:58:48 UTC
+++ graphviz-cgraph.cpp
@@ -67,11 +67,11 @@ Graphviz_CGraph::Node Graphviz_CGraph::addNode(const c
 /// interface implementation
 
 Graphviz_CGraph::Node Graphviz_CGraph::addNode(const char *name) {
-	return (Node)agnode(GRAPH, S(name), TRUE/*create*/);
+	return (Node)agnode(GRAPH, S(name), true/*create*/);
 }
 
 Graphviz_CGraph::Edge Graphviz_CGraph::addEdge(Node node1, Node node2, const char *name) {
-	return (Edge)agedge(GRAPH, NODE(node1), NODE(node2), S(name), TRUE/*create*/);
+	return (Edge)agedge(GRAPH, NODE(node1), NODE(node2), S(name), true/*create*/);
 }
 
 void Graphviz_CGraph::setDefaultNodeShape(const char *shapeValue) {

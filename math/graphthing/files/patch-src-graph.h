--- src/graph.h.orig	Fri Oct 25 13:50:30 2002
+++ src/graph.h	Fri Oct 25 13:52:29 2002
@@ -20,16 +20,16 @@
 class Graph
 {
 private:
-	vector<Edge *> E;
-	vector<Vertex *> V;
+	std::vector<Edge *> E;
+	std::vector<Vertex *> V;
 
 
 public:
 
-	typedef vector<Edge *>::iterator e_iterator;
-	typedef vector<Vertex *>::iterator v_iterator;
-	typedef vector<Edge *>::const_iterator e_const_iterator;
-	typedef vector<Vertex *>::const_iterator v_const_iterator;
+	typedef std::vector<Edge *>::iterator e_iterator;
+	typedef std::vector<Vertex *>::iterator v_iterator;
+	typedef std::vector<Edge *>::const_iterator e_const_iterator;
+	typedef std::vector<Vertex *>::const_iterator v_const_iterator;
 
 
 	Edge *e_selected_head;

--- src/vertex.h.orig	Tue Feb 12 05:47:23 2002
+++ src/vertex.h	Fri Oct 25 16:13:18 2002
@@ -15,12 +15,12 @@
 class Vertex
 {
 private:
-	vector<Edge *> edges;		/* Edges adjacent to this vertex */
+	std::vector<Edge *> edges;		/* Edges adjacent to this vertex */
 
 public:
 
-	typedef vector<Edge *>::iterator e_iterator;
-	typedef vector<Edge *>::const_iterator e_const_iterator;
+	typedef std::vector<Edge *>::iterator e_iterator;
+	typedef std::vector<Edge *>::const_iterator e_const_iterator;
 
 	String label;
 	int x;
@@ -45,7 +45,7 @@
 	void unhook (Edge *e);
 
 	Vertex &operator= (const Vertex &other);
-	friend ostream &operator<< (ostream &o, const Vertex &v);
+	friend std::ostream &operator<< (std::ostream &o, const Vertex &v);
 };
 
 #endif	/* __VERTEX_H__ */

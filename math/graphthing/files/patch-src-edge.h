--- src/edge.h.orig	Tue Feb 12 05:49:28 2002
+++ src/edge.h	Fri Oct 25 15:44:14 2002
@@ -26,7 +26,7 @@
 
 	Edge &operator= (const Edge &other);
 	bool operator== (const Edge &other) const;
-	friend ostream &operator<< (ostream &o, const Edge &e);
+	friend std::ostream &operator<< (std::ostream &o, const Edge &e);
 
 	bool incident_to (const Vertex *v1) const;
 	bool incident_to (const Vertex *v1, const Vertex *v2) const;

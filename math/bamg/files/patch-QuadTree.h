--- QuadTree.h.orig	Thu Dec 23 17:25:52 1999
+++ QuadTree.h	Thu Dec 18 22:38:50 2003
@@ -88,7 +88,7 @@
   ~QuadTree();
   QuadTree(Triangles * t,long nbv=-1);
   QuadTree();
-  friend ostream& operator <<(ostream& f, const  QuadTree & qt);
+  friend std::ostream& operator <<(std::ostream& f, const  QuadTree & qt);
 
 
 	

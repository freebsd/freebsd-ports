--- QuadTree.cpp.orig	Thu Dec 23 17:25:53 1999
+++ QuadTree.cpp	Fri Dec 19 00:03:06 2003
@@ -400,7 +400,7 @@
   root=0;
 }
 
-ostream& operator <<(ostream& f, const  QuadTree & qt)
+std::ostream& operator <<(std::ostream& f, const  QuadTree & qt)
 { 
   f << " the quadtree "  << endl;
   f << " NbQuadTreeBox = " << qt.NbQuadTreeBox 

--- freefem/fem/femParser.cpp.orig	Thu Oct 25 00:49:36 2001
+++ freefem/fem/femParser.cpp	Mon Jul 21 13:32:54 2003
@@ -2913,7 +2913,10 @@
               for( k =0; k<3*__mesh.getNumberOfCells();k++)  (s->name)->table[k] = 0;
               }
             else
-              {  (s->name)->table = new creal[__mesh.getNumberOfPoints()];
+              { // This is in order to avoid an internal compiler error
+			    // with gcc 2.95.4 (FreeBSD) 
+			  	int n = __mesh.getNumberOfPoints();
+			  (s->name)->table = new creal[n];
               for( k =0; k<__mesh.getNumberOfPoints();k++)  (s->name)->table[k] = 0;
               }
             }

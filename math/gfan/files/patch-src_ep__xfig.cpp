--- src/ep_xfig.cpp.orig	2017-06-20 14:47:37 UTC
+++ src/ep_xfig.cpp
@@ -75,12 +75,12 @@ bool XfigEnumerationPrinter::basis(const PolynomialSet
             }
         }
 
-  log2 xfig->printPolygon(p);
+  gfan_log2 xfig->printPolygon(p);
   xfig->drawPolygon(p,0);
 
   basisCounter++;
 
-  log2 fprintf(Stderr,"basisCounter:%i\n",basisCounter);
+  gfan_log2 fprintf(Stderr,"basisCounter:%i\n",basisCounter);
 
   return true;
 }

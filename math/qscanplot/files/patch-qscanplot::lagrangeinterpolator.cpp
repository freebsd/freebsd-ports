--- qscanplot/lagrangeinterpolator.cpp.orig	Sat Mar 30 17:30:42 2002
+++ qscanplot/lagrangeinterpolator.cpp	Thu Dec 23 20:19:26 2004
@@ -32,7 +32,7 @@
 // Implementation of class LagrangeInterpolator
 
 /** Constructor */
-LagrangeInterpolator::LagrangeInterpolator(double *px, double *py, int n=0)
+LagrangeInterpolator::LagrangeInterpolator(double *px=0, double *py=0, int n=0)
   : Interpolator(px,py), length(n) {}
 
 /** Sets the length of the vectors */

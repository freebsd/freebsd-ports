--- qscanplot/lagrangeinterpolator.h.orig	Sat Mar 30 17:30:43 2002
+++ qscanplot/lagrangeinterpolator.h	Thu Dec 23 20:20:14 2004
@@ -41,7 +41,7 @@
   
 public:
   
-  LagrangeInterpolator(double*px=0, double*py=0, int n=0); // constructor
+  LagrangeInterpolator(double*px, double*py, int n); // constructor
 
 public:
   void   setLength(int n);

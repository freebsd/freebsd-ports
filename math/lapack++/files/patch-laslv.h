--- include/laslv.h~	Tue Feb 29 05:42:27 2000
+++ include/laslv.h	Wed May 22 21:51:02 2002
@@ -51,7 +51,7 @@
 void LaEigSolve(const LaSymmMatDouble &S, LaVectorDouble &eigvals, 
     LaGenMatDouble &eigvec);
 void LaEigSolveIP(LaSymmMatDouble &S, LaVectorDouble &eigvals);
-void LaEigSolveVecIP(LaSymmMatDouble &S, LaVectorDouble &eigvals);
+void LaEigSolveVecIP(LaGenMatDouble &A, LaVectorDouble &eigvals);
 #endif
 
 

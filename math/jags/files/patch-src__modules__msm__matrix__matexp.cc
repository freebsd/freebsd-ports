--- src/modules/msm/matrix/matexp.cc.orig	2009-12-26 15:36:17.000000000 -0500
+++ src/modules/msm/matrix/matexp.cc	2009-12-26 15:36:54.000000000 -0500
@@ -73,6 +73,8 @@
     int info = 0;
     F77_DGESV (&n, &n, Acopy, &n, ipiv, X, &n, &info);
     if (info != 0) {
+	delete [] Acopy;
+	delete [] ipiv;
 	throw runtime_error("Unable to solve linear equations");
     }
   

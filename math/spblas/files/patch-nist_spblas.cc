--- nist_spblas.cc.orig	2012-01-05 12:33:16.000000000 -0500
+++ nist_spblas.cc	2012-01-05 12:37:11.000000000 -0500
@@ -54,7 +54,17 @@
 #define ERROR_RETURN(ret_val) return ret_val
 #endif
 
+/* dummy routines for real version of usdot to compile. */
+
+inline const double& conj(const double &x)
+{ 
+  return x;
+}
 
+inline const float& conj(const float &x)
+{ 
+  return x;
+}
 
 using namespace std;
 
@@ -1274,19 +1284,6 @@
 /*  Level 1 generic routines   */
 /* --------------------------- */
 
-/* dummy routines for real version of usdot to compile. */
-
-inline const double& conj(const double &x)
-{ 
-  return x;
-}
-
-inline const float& conj(const float &x)
-{ 
-  return x;
-}
-
-
 template <class T>
 void BLAS_xusdot( enum blas_conj_type conj_flag, int nz,
     const T *x,  const int *index,  const T *y, int incy,

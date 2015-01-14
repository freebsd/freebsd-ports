--- include/armadillo_bits/config.hpp.orig	2015-01-09 19:09:21.294357075 -0500
+++ include/armadillo_bits/config.hpp	2015-01-09 19:12:51.862339555 -0500
@@ -24,7 +24,7 @@
 #endif
 
 #if !defined(ARMA_USE_ARPACK)
-// #define ARMA_USE_ARPACK
+#define ARMA_USE_ARPACK
 //// Uncomment the above line if you have ARPACK or a high-speed replacement for ARPACK.
 //// ARPACK is required for eigendecompositions of sparse matrices, eg. eigs_sym() 
 #endif
@@ -54,7 +54,7 @@
 //// Uncomment the above line if you want to use Intel MKL mkl_malloc() and mkl_free() instead of standard malloc() and free()
 
 // #define ARMA_USE_ATLAS
-// #define ARMA_ATLAS_INCLUDE_DIR /usr/include/
+// #define ARMA_ATLAS_INCLUDE_DIR /usr/local/include/
 //// If you're using ATLAS and the compiler can't find cblas.h and/or clapack.h
 //// uncomment the above define and specify the appropriate include directory.
 //// Make sure the directory has a trailing /

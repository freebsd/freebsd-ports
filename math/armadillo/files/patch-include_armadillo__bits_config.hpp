--- include/armadillo_bits/config.hpp.orig	2016-08-03 19:20:44 UTC
+++ include/armadillo_bits/config.hpp
@@ -32,13 +32,13 @@
 #endif
 
 #if !defined(ARMA_USE_ARPACK)
-// #define ARMA_USE_ARPACK
+#define ARMA_USE_ARPACK
 //// Uncomment the above line if you have ARPACK or a high-speed replacement for ARPACK.
 //// ARPACK is required for eigen decompositions of complex sparse matrices
 #endif
 
 #if !defined(ARMA_USE_SUPERLU)
-// #define ARMA_USE_SUPERLU
+#define ARMA_USE_SUPERLU
 //// Uncomment the above line if you have SuperLU.
 //// SuperLU is used for solving sparse linear systems via spsolve()
 //// Caveat: only SuperLU version 5.2 can be used!
@@ -76,7 +76,7 @@
 //// Uncomment the above line if you want to use Intel MKL mkl_malloc() and mkl_free() instead of standard malloc() and free()
 
 // #define ARMA_USE_ATLAS
-// #define ARMA_ATLAS_INCLUDE_DIR /usr/include/
+#define ARMA_ATLAS_INCLUDE_DIR /usr/local/include/
 //// If you're using ATLAS and the compiler can't find cblas.h and/or clapack.h
 //// uncomment the above define and specify the appropriate include directory.
 //// Make sure the directory has a trailing /

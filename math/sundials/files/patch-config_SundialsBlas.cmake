--- config/SundialsBlas.cmake.orig	2017-11-07 23:47:45 UTC
+++ config/SundialsBlas.cmake
@@ -74,6 +74,7 @@ if(BLAS_LIBRARIES)
 
   # Attempt to link the "ltest" executable
   try_compile(LTEST_OK ${BlasTest_DIR} ${BlasTest_DIR}
+    LINK_DIRECTORIES ${FREEBSD_GCC_DIR}
     ltest OUTPUT_VARIABLE MY_OUTPUT)
 
   # To ensure we do not use stuff from the previous attempts, 

--- config/SundialsLapack.cmake.orig	2017-11-07 23:47:45 UTC
+++ config/SundialsLapack.cmake
@@ -75,6 +75,7 @@ if(LAPACK_LIBRARIES)
 
   # Attempt to link the "ltest" executable
   try_compile(LTEST_OK ${LapackTest_DIR} ${LapackTest_DIR}
+    LINK_DIRECTORIES ${FREEBSD_GCC_DIR}
     ltest OUTPUT_VARIABLE MY_OUTPUT)
 
   # To ensure we do not use stuff from the previous attempts, 

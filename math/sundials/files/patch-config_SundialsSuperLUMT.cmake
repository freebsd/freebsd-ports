--- config/SundialsSuperLUMT.cmake.orig	2017-12-28 04:44:39 UTC
+++ config/SundialsSuperLUMT.cmake
@@ -61,7 +61,7 @@ if(SUPERLUMT_LIBRARY AND SUPERLUMT_LIBRA
     "}\n")
 
   # Attempt to link the "ltest" executable
-  try_compile(LTEST_OK ${SUPERLUMT_TEST_DIR} ${SUPERLUMT_TEST_DIR} ltest OUTPUT_VARIABLE MY_OUTPUT)
+  try_compile(LTEST_OK ${SUPERLUMT_TEST_DIR} ${SUPERLUMT_TEST_DIR} LINK_DIRECTORIES ${FREEBSD_GCC_DIR} ltest OUTPUT_VARIABLE MY_OUTPUT)
       
   # To ensure we do not use stuff from the previous attempts, 
   # we must remove the CMakeFiles directory.

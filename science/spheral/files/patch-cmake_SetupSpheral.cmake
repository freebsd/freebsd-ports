- eliminate the need to use git

--- cmake/SetupSpheral.cmake.orig	2023-07-06 16:44:17 UTC
+++ cmake/SetupSpheral.cmake
@@ -176,7 +176,7 @@ if (ENABLE_TESTS)
 
   # Find the test files we want to install
   execute_process(
-    COMMAND git ls-files tests
+    COMMAND find tests -type f
     WORKING_DIRECTORY ${SPHERAL_ROOT_DIR}
     OUTPUT_VARIABLE test_files1)
   string(REPLACE "\n" " " test_files ${test_files1})

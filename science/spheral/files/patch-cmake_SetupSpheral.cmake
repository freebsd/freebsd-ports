- eliminate the need to use git

--- cmake/SetupSpheral.cmake.orig	2024-01-20 00:52:15 UTC
+++ cmake/SetupSpheral.cmake
@@ -169,7 +169,7 @@ if (ENABLE_TESTS)
   set(test_files1 "")
   if (EXISTS "${CMAKE_SOURCE_DIR}/.git")
     execute_process(
-      COMMAND git ls-files tests
+      COMMAND find tests -type f
       WORKING_DIRECTORY ${SPHERAL_ROOT_DIR}
       OUTPUT_VARIABLE test_files1)
   else()

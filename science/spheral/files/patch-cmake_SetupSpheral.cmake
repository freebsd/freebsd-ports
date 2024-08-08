- eliminate the need to use git

--- cmake/SetupSpheral.cmake.orig	2024-07-11 14:54:59 UTC
+++ cmake/SetupSpheral.cmake
@@ -21,8 +21,8 @@ include(Compilers)
 #-------------------------------------------------------------------------------
 
 # Need to define Python paths here as BLT finds it's own Python package.
-set(Python_EXECUTABLE ${python_DIR}/bin/python3)
-set(Python3_EXECUTABLE ${python_DIR}/bin/python3)
+#set(Python_EXECUTABLE ${python_DIR}/bin/python3)
+#set(Python3_EXECUTABLE ${python_DIR}/bin/python3)
 
 set(ENABLE_MPI ON CACHE BOOL "")
 set(ENABLE_OPENMP ON CACHE BOOL "")
@@ -167,7 +167,7 @@ if (ENABLE_TESTS)
   set(test_files1 "")
   if (EXISTS "${CMAKE_SOURCE_DIR}/.git")
     execute_process(
-      COMMAND git ls-files tests
+      COMMAND find tests -type f
       WORKING_DIRECTORY ${SPHERAL_ROOT_DIR}
       OUTPUT_VARIABLE test_files1)
   else()

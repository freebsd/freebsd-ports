- eliminate the need to use git

--- cmake/SetupSpheral.cmake.orig	2025-07-23 20:11:18 UTC
+++ cmake/SetupSpheral.cmake
@@ -27,8 +27,8 @@ include(Compilers)
 #-------------------------------------------------------------------------------
 
 # Need to define Python paths here as BLT finds it's own Python package.
-set(Python_EXECUTABLE ${python_DIR}/bin/python3)
-set(Python3_EXECUTABLE ${python_DIR}/bin/python3)
+#set(Python_EXECUTABLE ${python_DIR}/bin/python3)
+#set(Python3_EXECUTABLE ${python_DIR}/bin/python3)
 
 set(ENABLE_MPI ON CACHE BOOL "")
 set(ENABLE_OPENMP ON CACHE BOOL "")

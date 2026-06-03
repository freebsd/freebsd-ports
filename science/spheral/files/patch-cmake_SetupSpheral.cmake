- eliminate the need to use git

--- cmake/SetupSpheral.cmake.orig	2026-04-01 07:49:10 UTC
+++ cmake/SetupSpheral.cmake
@@ -28,8 +28,8 @@ include(Compilers)
 #-------------------------------------------------------------------------------
 
 # Need to define Python paths here as BLT finds it's own Python package.
-set(Python_EXECUTABLE ${python_DIR}/bin/python3)
-set(Python3_EXECUTABLE ${python_DIR}/bin/python3)
+#set(Python_EXECUTABLE ${python_DIR}/bin/python3)
+#set(Python3_EXECUTABLE ${python_DIR}/bin/python3)
 
 set(ENABLE_MPI ON CACHE BOOL "")
 set(ENABLE_OPENMP ON CACHE BOOL "")

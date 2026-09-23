-- Do not hard-code a Python interpreter under ${python_DIR}; the port uses
-- BINARY_ALIAS and Python_EXECUTABLE arguments to control Python discovery.

--- cmake/SetupSpheral.cmake.orig	2026-06-23 16:46:22 UTC
+++ cmake/SetupSpheral.cmake
@@ -33,8 +33,8 @@ include(Compilers)
 #-------------------------------------------------------------------------------
 
 # Need to define Python paths here as BLT finds it's own Python package.
-set(Python_EXECUTABLE ${python_DIR}/bin/python3)
-set(Python3_EXECUTABLE ${python_DIR}/bin/python3)
+#set(Python_EXECUTABLE ${python_DIR}/bin/python3)
+#set(Python3_EXECUTABLE ${python_DIR}/bin/python3)
 
 set(ENABLE_MPI ON CACHE BOOL "")
 set(ENABLE_OPENMP ON CACHE BOOL "")

--- unittests/gtest/cmake/internal_utils.cmake.orig	2024-04-04 16:25:44 UTC
+++ unittests/gtest/cmake/internal_utils.cmake
@@ -236,7 +236,7 @@ endfunction()
 endfunction()
 
 # Sets PYTHONINTERP_FOUND and PYTHON_EXECUTABLE.
-find_package(PythonInterp)
+find_package(PythonInterp ${FREEBSD_PYTHON_VER} EXACT)
 
 # cxx_test_with_flags(name cxx_flags libs srcs...)
 #

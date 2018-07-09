--- cmake_support/FindPython.cmake.orig	2018-07-08 23:04:29 UTC
+++ cmake_support/FindPython.cmake
@@ -75,7 +75,6 @@ macro(_find_python_bin PYTHON_ROOT VERSI
       NAMES "python${_VERSION_NO_DOTS}" "python${VERSION}" python.exe
       HINTS "${PYTHON_ROOT}"
       PATH_SUFFIXES bin
-      NO_SYSTEM_ENVIRONMENT_PATH NO_DEFAULT_PATH
     )
   else()
     find_program(PYTHON_BINARY

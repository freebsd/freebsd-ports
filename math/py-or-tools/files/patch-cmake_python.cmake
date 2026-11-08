-- Require the exact Python version of the selected flavor.
-- Otherwise cmake may pick another installed Python and build for the wrong flavor.

--- cmake/python.cmake.orig	2026-10-18 17:28:09 UTC
+++ cmake/python.cmake
@@ -42,7 +42,7 @@ list(APPEND CMAKE_SWIG_FLAGS "-DOR_DLL=")
 list(APPEND CMAKE_SWIG_FLAGS "-DOR_DLL=")
 
 # Find Python 3
-find_package(Python3 REQUIRED COMPONENTS Interpreter Development.Module)
+find_package(Python3 ${FREEBSD_PYTHON_VER} REQUIRED EXACT COMPONENTS Interpreter Development.Module)
 list(APPEND CMAKE_SWIG_FLAGS "-py3" "-DPY3")
 
 # Find if the python module is available,

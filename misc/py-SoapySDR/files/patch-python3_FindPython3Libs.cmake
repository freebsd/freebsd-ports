--- python3/FindPython3Libs.cmake.orig	2018-06-19 06:36:21 UTC
+++ python3/FindPython3Libs.cmake
@@ -46,7 +46,7 @@ INCLUDE(CMakeFindFrameworks)
 # Search for the python framework on Apple.
 # CMAKE_FIND_FRAMEWORKS(Python)
 
-FOREACH(_CURRENT_VERSION 3.5 3.4 3.3 3.2 3.1 3.0)
+FOREACH(_CURRENT_VERSION ${FREEBSD_PYTHON_VER2})
   IF(_CURRENT_VERSION GREATER 3.1)
       SET(_32FLAGS "m" "u" "mu" "dm" "du" "dmu" "")
   ELSE()

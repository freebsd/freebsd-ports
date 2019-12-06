--- cmake/modules/FindPython3Interp.cmake.orig	2019-09-13 18:07:41 UTC
+++ cmake/modules/FindPython3Interp.cmake
@@ -69,7 +69,7 @@
 
 unset(_Python3_NAMES)
 
-set(_PYTHON3_VERSIONS 3.6 3.5 3.4 3.3 3.2 3.1 3.0)
+set(_PYTHON3_VERSIONS 3.8 3.7 3.6 3.5 3.4 3.3 3.2 3.1 3.0)
 
 if(Python3Interp_FIND_VERSION)
     if(Python3Interp_FIND_VERSION_COUNT GREATER 1)

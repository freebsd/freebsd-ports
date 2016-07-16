Adjust parameters passed to _pkg_check_modules_internal().
Required for building with CMake 3.6.0.

Submitted upstream: https://sourceforge.net/p/plplot/patches/33/
--- cmake/modules/pkg-config.cmake.orig	2016-07-16 10:36:31 UTC
+++ cmake/modules/pkg-config.cmake
@@ -120,8 +120,10 @@ macro(pkg_check_pkgconfig _package _incl
   
   if(CMAKE_VERSION VERSION_LESS "3.1")
     _pkg_check_modules_internal(0 0 ${_prefix} "${_package}")
-  else(CMAKE_VERSION VERSION_LESS "3.1")
+  elseif(CMAKE_VERSION VERSION_LESS "3.6")
     _pkg_check_modules_internal(0 0 0 0 ${_prefix} "${_package}")
+  else(CMAKE_VERSION VERSION_LESS "3.1")
+    _pkg_check_modules_internal(0 0 0 0 0 ${_prefix} "${_package}")
   endif(CMAKE_VERSION VERSION_LESS "3.1")
     
   if(${_prefix}_FOUND)

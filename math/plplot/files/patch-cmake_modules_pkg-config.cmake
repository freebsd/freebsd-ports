The *internal* _pkg_check_modules_internal macro of cmake gained another 
parameter in cmake-3.13.

https://gitlab.kitware.com/cmake/cmake/commit/7aa26cf0e9319be3f7785763eb3699823453eb60

--- cmake/modules/pkg-config.cmake.orig	2018-11-25 12:01:15 UTC
+++ cmake/modules/pkg-config.cmake
@@ -122,8 +122,10 @@ macro(pkg_check_pkgconfig _package _include_DIR _link_
     _pkg_check_modules_internal(0 0 ${_prefix} "${_package}")
   elseif(CMAKE_VERSION VERSION_LESS "3.6")
     _pkg_check_modules_internal(0 0 0 0 ${_prefix} "${_package}")
-  else(CMAKE_VERSION VERSION_LESS "3.1")
+  elseif(CMAKE_VERSION VERSION_LESS "3.13")
     _pkg_check_modules_internal(0 0 0 0 0 ${_prefix} "${_package}")
+  else(CMAKE_VERSION VERSION_LESS "3.1")
+    _pkg_check_modules_internal(0 0 0 0 0 0 ${_prefix} "${_package}")
   endif(CMAKE_VERSION VERSION_LESS "3.1")
 
   if(${_prefix}_FOUND)

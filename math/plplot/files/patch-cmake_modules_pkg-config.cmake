Includes the following upstream commit to make the port work with CMake 3.1.0:

commit 772223c638ecf5dc740c9f3dd7a6883c6d2c83d2
Author: Alan W. Irwin <airwin@users.sourceforge.net>
Date:   Sun Dec 7 09:06:08 2014 -0800

    Adjust for internal CMake-3.1 pkg-config change.

    There is a report from Greg Jung <gvjung@gmail.com> that the
    internal CMake command

    _pkg_check_modules_internal(0 0 ${_prefix} "${_package}")

    must be changed to

    _pkg_check_modules_internal(0 0 0 0 ${_prefix} "${_package}")

    for CMake-3.1 in order to build the cairo device properly.  Accordingly, I have made that adjustment.

    Tested by Alan W. Irwin <airwin@users> on Linux using CMake-3.0.2
    by building the cairo device.

    N.B. currently untested for CMake-3.1.

    ToDo:

    Extensive tests on CMake-3.1 (once that version is closer to release)
    still need to be done since the change in the pkg-config support by
    CMake may need other adjustments as well.

--- cmake/modules/pkg-config.cmake.orig	2014-02-06 00:06:07.000000000 -0500
+++ cmake/modules/pkg-config.cmake
@@ -1,6 +1,6 @@
 # cmake/modules/pkg-config.cmake
 #
-# Copyright (C) 2006  Alan W. Irwin
+# Copyright (C) 2006-2015 Alan W. Irwin
 #
 # This file is part of PLplot.
 #
@@ -39,7 +39,7 @@ include(FindPkgConfig)
 
 if(PKG_CONFIG_EXECUTABLE)
   message(STATUS "Looking for pkg-config - found")
-  set(PKG_CONFIG_DIR "${LIB_DIR}/pkgconfig")
+  set(PKG_CONFIG_DIR "${LIB_DIR}data/pkgconfig")
   set(env_PKG_CONFIG_PATH $ENV{PKG_CONFIG_PATH})
 
   # Will likely need WIN32 and CYGWIN stanzas as well
@@ -94,7 +94,12 @@ macro(pkg_check_pkgconfig _package _include_DIR _link_DIR _link_FLAGS _cflags _v
     set(_xprefix ${_prefix})
   endif(FORCE_EXTERNAL_STATIC)
   
-  _pkg_check_modules_internal(0 0 ${_prefix} "${_package}")
+  if(CMAKE_VERSION VERSION_LESS "3.1")
+    _pkg_check_modules_internal(0 0 ${_prefix} "${_package}")
+  else(CMAKE_VERSION VERSION_LESS "3.1")
+    _pkg_check_modules_internal(0 0 0 0 ${_prefix} "${_package}")
+  endif(CMAKE_VERSION VERSION_LESS "3.1")
+    
   if(${_prefix}_FOUND)
     cmake_link_flags(${_link_FLAGS} "${${_xprefix}_LDFLAGS}")
     # If libraries cannot be not found, then that is equivalent to whole

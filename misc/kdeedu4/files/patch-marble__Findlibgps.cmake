--- ./marble/Findlibgps.cmake.orig	2009-05-06 14:13:59.000000000 +0400
+++ ./marble/Findlibgps.cmake	2010-03-14 00:08:03.860024388 +0300
@@ -1,10 +1,16 @@
-# - Find Gpsd libs - gps daemon library
-#
-# This module finds if Gpsd is installed.
-#
-# Copyright (c) 2006, Andrew Manson, <g.real.ate@gmail.com>
-#
+# LIBGPS_FOUND - system has the LIBGPS library
+# LIBGPS_INCLUDE_DIR - the LIBGPS include directory
+# LIBGPS_LIBRARIES - The libraries needed to use LIBGPS
 
-include(FindPkgConfig)
+if(LIBGPS_INCLUDE_DIR AND LIBGPS_LIBRARIES)
+  set(LIBGPS_FOUND TRUE)
+else(LIBGPS_INCLUDE_DIR AND LIBGPS_LIBRARIES)
 
-pkg_check_modules(libgps libgps>=2.35)
+  find_path(LIBGPS_INCLUDE_DIR NAMES gps.h)
+  find_library(LIBGPS_LIBRARIES NAMES gps)
+
+  include(FindPackageHandleStandardArgs)
+  find_package_handle_standard_args(libgps DEFAULT_MSG LIBGPS_INCLUDE_DIR LIBGPS_LIBRARIES)
+
+  mark_as_advanced(LIBGPS_INCLUDE_DIR LIBGPS_LIBRARIES)
+endif(LIBGPS_INCLUDE_DIR AND LIBGPS_LIBRARIES)

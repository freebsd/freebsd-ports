$OpenBSD: patch-cmake_modules_FindGStreamer_cmake,v 1.1 2015/09/27 08:23:55 ajacoutot Exp $

https://bugzilla.gnome.org/show_bug.cgi?id=751382

--- cmake/modules/FindGStreamer.cmake.orig	Tue Jul  8 20:38:36 2014
+++ cmake/modules/FindGStreamer.cmake	Sun Sep 27 09:12:31 2015
@@ -36,6 +36,7 @@ if (PKG_CONFIG_FOUND)
     exec_program(${PKG_CONFIG_EXECUTABLE}
                  ARGS --variable pluginsdir gstreamer-${GSTREAMER_ABI_VERSION}
                  OUTPUT_VARIABLE PKG_GSTREAMER_PLUGIN_DIR)
+    set(GSTREAMER_DEFINITIONS ${PKG_GSTREAMER_CFLAGS})
 endif()
 
 find_library(GSTREAMER_LIBRARY

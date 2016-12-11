Don't use custom code to find the include dirs for gstreamer 1.0 (core).
Since 1.6.0 there are multiple include paths. So use pkg-config to find
which. IMO the rest of this file should use pkg-config....

--- cmake/FindGStreamer_1_0.cmake.orig	2016-10-21 07:29:51 UTC
+++ cmake/FindGStreamer_1_0.cmake
@@ -78,7 +78,8 @@ endmacro()
 # 1.1. Find headers and libraries
 set(GLIB_ROOT_DIR ${GSTREAMER_1_0_ROOT_DIR})
 find_package(Glib REQUIRED)
-FIND_GSTREAMER_COMPONENT(GSTREAMER_1_0 gstreamer-1.0 gstreamer-1.0)
+#FIND_GSTREAMER_COMPONENT(GSTREAMER_1_0 gstreamer-1.0 gstreamer-1.0)
+pkg_check_modules (GSTREAMER_1_0 gstreamer-1.0)
 FIND_GSTREAMER_COMPONENT(GSTREAMER_1_0_BASE gstreamer-base-1.0 gstbase-1.0)
 
 # 1.2. Check Gstreamer version

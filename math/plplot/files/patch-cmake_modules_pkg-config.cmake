--- ./cmake/modules/pkg-config.cmake.orig	2009-09-06 21:04:43.000000000 +0200
+++ ./cmake/modules/pkg-config.cmake	2009-12-26 23:55:00.000000000 +0100
@@ -48,7 +48,7 @@
 if(PKG_CONFIG_EXECUTABLE)
   message(STATUS "Looking for pkg-config - found")
   set(pkg_config_true "")
-  set(PKG_CONFIG_DIR ${LIB_DIR}/pkgconfig)
+  set(PKG_CONFIG_DIR ${LIB_DIR}data/pkgconfig)
   set(PKG_CONFIG_ENV PKG_CONFIG_PATH=${PKG_CONFIG_DIR})
 else(PKG_CONFIG_EXECUTABLE)
   message(STATUS "Looking for pkg-config - not found")

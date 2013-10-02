--- cmake/modules/pkg-config.cmake.orig	2012-01-05 14:59:36.000000000 +0100
+++ cmake/modules/pkg-config.cmake	2013-10-01 23:01:57.000000000 +0200
@@ -39,7 +39,7 @@
 
 if(PKG_CONFIG_EXECUTABLE)
   message(STATUS "Looking for pkg-config - found")
-  set(PKG_CONFIG_DIR ${LIB_DIR}/pkgconfig)
+  set(PKG_CONFIG_DIR ${LIB_DIR}data/pkgconfig)
   set(PKG_CONFIG_ENV PKG_CONFIG_PATH=${PKG_CONFIG_DIR})
 else(PKG_CONFIG_EXECUTABLE)
   message(STATUS "Looking for pkg-config - not found")

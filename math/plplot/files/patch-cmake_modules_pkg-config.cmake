--- cmake/modules/pkg-config.cmake.orig	2015-04-12 10:08:04 UTC
+++ cmake/modules/pkg-config.cmake
@@ -39,7 +39,7 @@ include(FindPkgConfig)
 
 if(PKG_CONFIG_EXECUTABLE)
   message(STATUS "Looking for pkg-config - found")
-  set(PKG_CONFIG_DIR "${LIB_DIR}/pkgconfig")
+  set(PKG_CONFIG_DIR "${LIB_DIR}data/pkgconfig")
   set(env_PKG_CONFIG_PATH $ENV{PKG_CONFIG_PATH})
 
   # Will likely need WIN32 and CYGWIN stanzas as well

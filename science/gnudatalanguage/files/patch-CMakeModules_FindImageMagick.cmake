--- CMakeModules/FindImageMagick.cmake.orig	2024-11-02 17:32:21 UTC
+++ CMakeModules/FindImageMagick.cmake
@@ -72,7 +72,7 @@ set(ENV{PATH} "${MAGICKDIR}/bin:$ENV{PATH}")
 
 # Define variables
 set(ENV{PATH} "${MAGICKDIR}/bin:$ENV{PATH}")
-set(ENV{PKG_CONFIG_PATH} "${MAGICKDIR}/lib/pkgconfig/:$ENV{PKG_CONFIG_PATH}")
+set(ENV{PKG_CONFIG_PATH} "${MAGICKDIR}/libdata/pkgconfig/:$ENV{PKG_CONFIG_PATH}")
 
 #---------------------------------------------------------------------
 # Helper functions

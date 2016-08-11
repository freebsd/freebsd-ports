--- CMakeModules/Findlibps.cmake.orig	2016-04-29 17:03:25 UTC
+++ CMakeModules/Findlibps.cmake
@@ -1,4 +1,4 @@
-find_path(LIBPSPKG libps.pc PATH_SUFFIXES lib lib/pkgconfig lib64/pkgconfig)
+find_path(LIBPSPKG libps.pc PATH_SUFFIXES lib libdata/pkgconfig lib/pkgconfig lib64/pkgconfig)
 include(FindPackageHandleStandardArgs)
 if(LIBPSPKG)
 	set(ENV{PKG_CONFIG_PATH} ${LIBPSPKG}) # pkg search path

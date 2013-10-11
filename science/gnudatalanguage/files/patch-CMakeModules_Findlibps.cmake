--- ./CMakeModules/Findlibps.cmake.orig	2013-01-03 00:26:23.000000000 +0100
+++ ./CMakeModules/Findlibps.cmake	2013-09-30 13:27:07.000000000 +0200
@@ -1,4 +1,4 @@
-find_path(LIBPSPKG libps.pc PATH_SUFFIXES lib lib/pkgconfig lib64/pkgconfig)
+find_path(LIBPSPKG libps.pc PATH_SUFFIXES lib libdata/pkgconfig lib/pkgconfig lib64/pkgconfig)
 include(FindPackageHandleStandardArgs)
 if(LIBPSPKG)
 	set(ENV{PKG_CONFIG_PATH} ${LIBPSPKG}) # pkg search path

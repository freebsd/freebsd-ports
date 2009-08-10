--- ./cmake/modules/FindCFitsio.cmake.orig	2008-12-21 20:20:00.000000000 +0000
+++ ./cmake/modules/FindCFitsio.cmake	2009-01-30 22:25:02.000000000 +0000
@@ -23,19 +23,19 @@
   IF (NOT WIN32)
     find_package(PkgConfig)
     IF (PKG_CONFIG_FOUND)    
-      pkg_check_modules(CFITSIO cfitsio)
+      pkg_check_modules(PC_CFITSIO cfitsio)
     ENDIF (PKG_CONFIG_FOUND)
   ENDIF (NOT WIN32)
 
   find_path(CFITSIO_INCLUDE_DIR fitsio.h
-    ${CFITSIO_INCLUDE_DIRS}
+    ${PC_CFITSIO_INCLUDE_DIRS}
     ${_obIncDir}
     ${GNUWIN32_DIR}/include
   )
 
   find_library(CFITSIO_LIBRARIES NAMES cfitsio libcfitsio
     PATHS
-    ${CFITSIO_LIBRARY_DIRS}
+    ${PC_CFITSIO_LIBRARY_DIRS}
     ${_obLinkDir}
     ${GNUWIN32_DIR}/lib
   )

--- cmake/modules/FindQtOAuth.cmake.orig	2016-10-07 15:54:41 UTC
+++ cmake/modules/FindQtOAuth.cmake
@@ -18,16 +18,17 @@ if (QTOAUTH_INCLUDE_DIR AND QTOAUTH_LIBR
 else (QTOAUTH_INCLUDE_DIR AND QTOAUTH_LIBRARY)
   if (NOT WIN32)
     find_package(PkgConfig)
-    pkg_check_modules(PC_QTOAUTH QUIET qoauth)
+    pkg_check_modules(PC_QTOAUTH QUIET qoauth-qt5)
     set(QTOAUTH_DEFINITIONS ${PC_QTOAUTH_CFLAGS_OTHER})
   endif(NOT WIN32)
 
-  find_library(QTOAUTH_LIBRARY NAMES qoauth
+  find_library(QTOAUTH_LIBRARY NAMES qoauth-qt5
     HINTS ${PC_QTOAUTH_LIBDIR} ${PC_QTOAUTH_LIBRARY_DIRS}
   )
 
   find_path(QTOAUTH_INCLUDE_DIR QtOAuth/interface.h
     HINTS ${PC_QTOAUTH_INCLUDEDIR} ${PC_QTOAUTH_INCLUDE_DIRS}
+    PATH_SUFFIXES QtOAuth-qt5
   )
 
   include(FindPackageHandleStandardArgs)

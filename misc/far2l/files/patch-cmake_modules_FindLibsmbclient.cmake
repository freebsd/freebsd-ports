--- cmake/modules/FindLibsmbclient.cmake.orig	2020-10-21 22:24:08 UTC
+++ cmake/modules/FindLibsmbclient.cmake
@@ -21,11 +21,6 @@ else (LIBSMBCLIENT_LIBRARIES AND LIBSMBCLIENT_INCLUDE_
   find_path(LIBSMBCLIENT_INCLUDE_DIR
     NAMES
       libsmbclient.h
-    PATHS
-      /usr/include
-      /usr/local/include
-      /opt/local/include
-      /sw/include
     PATH_SUFFIXES
       samba-4.0
       samba4

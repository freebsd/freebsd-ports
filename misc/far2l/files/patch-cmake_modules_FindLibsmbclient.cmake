--- cmake/modules/FindLibsmbclient.cmake.orig	2020-06-22 23:39:14 UTC
+++ cmake/modules/FindLibsmbclient.cmake
@@ -21,23 +21,17 @@ else (LIBSMBCLIENT_LIBRARIES AND LIBSMBCLIENT_INCLUDE_
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
+      samba4
   )
 
   find_library(SMBCLIENT_LIBRARY
     NAMES
       smbclient
-    PATHS
-      /usr/lib
-      /usr/local/lib
-      /opt/local/lib
-      /sw/lib
+    PATH_SUFFIXES
+      samba-4.0
+      samba4
   )
 
   if (SMBCLIENT_LIBRARY)

--- CMakeModules/FindQHULL.cmake.orig	2017-02-07 21:12:49 UTC
+++ CMakeModules/FindQHULL.cmake
@@ -16,7 +16,7 @@ find_path(
 if( QHULL_INCLUDE_DIR )
   find_library(
     QHULL_LIBRARY
-    NAMES libqhullstatic libqhull qhullstatic qhull 
+    NAMES libqhull qhull
     PATHS /usr/lib64 /usr/local/lib /usr/lib
   )
   if( QHULL_LIBRARY )

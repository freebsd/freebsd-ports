--- cmake/modules/FREETYPEConfig.cmake.orig	2008-04-07 22:45:10.000000000 +0200
+++ cmake/modules/FREETYPEConfig.cmake	2015-12-02 14:40:47.871063000 +0100
@@ -1,10 +1,10 @@
 #
 # Find the native FREETYPE includes and library
 # (from Scribus)
-  FIND_PATH(FREETYPE_INCLUDE_DIR_FT2BUILD ft2build.h
-    /usr/include/
-    /usr/local/include/
-    /usr/X11R6/include/
+  FIND_PATH(FREETYPE_INCLUDE_DIR_FT2BUILD freetype2/ft2build.h
+    /usr/include
+    /usr/local/include
+    /usr/X11R6/include
     NO_CMAKE_SYSTEM_PATH
   )
 

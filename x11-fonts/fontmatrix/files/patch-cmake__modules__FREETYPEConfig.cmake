--- cmake/modules/FREETYPEConfig.cmake.orig	2008-04-07 20:45:10 UTC
+++ cmake/modules/FREETYPEConfig.cmake
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
 

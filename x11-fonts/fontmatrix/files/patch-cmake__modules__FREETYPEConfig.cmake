--- cmake/modules/FREETYPEConfig.cmake.orig	2008-04-07 23:45:10.000000000 +0300
+++ cmake/modules/FREETYPEConfig.cmake	2013-12-23 19:53:13.000000000 +0200
@@ -1,14 +1,14 @@
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
 
-  FIND_PATH(FREETYPE_INCLUDE_DIR_FTHEADER freetype/config/ftheader.h
+  FIND_PATH(FREETYPE_INCLUDE_DIR_FTHEADER config/ftheader.h
     /usr/include/freetype2
     /usr/local/include/freetype2
     /usr/X11R6/include/freetype2

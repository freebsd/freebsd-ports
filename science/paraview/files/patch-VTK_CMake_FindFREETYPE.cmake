--- VTK/CMake/FindFREETYPE.cmake.orig	2011-04-13 19:17:14.000000000 +0300
+++ VTK/CMake/FindFREETYPE.cmake	2013-12-23 19:50:03.000000000 +0200
@@ -10,9 +10,9 @@
 # also defined, but not for general use are
 # FREETYPE_LIBRARY, where to find the FREETYPE library.
 
-FIND_PATH(FREETYPE_INCLUDE_DIR_FT2BUILD ft2build.h)
+FIND_PATH(FREETYPE_INCLUDE_DIR_FT2BUILD freetype2/ft2build.h)
 
-FIND_PATH(FREETYPE_INCLUDE_DIR_FTHEADER freetype/config/ftheader.h
+FIND_PATH(FREETYPE_INCLUDE_DIR_FTHEADER config/ftheader.h
   /usr/include/freetype2
   /usr/local/include/freetype2
 )

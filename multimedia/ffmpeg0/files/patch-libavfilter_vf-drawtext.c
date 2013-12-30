--- libavfilter/vf_drawtext.c.orig	2013-12-06 18:18:29.000000000 +0100
+++ libavfilter/vf_drawtext.c	2013-12-06 18:18:49.000000000 +0100
@@ -41,7 +41,6 @@
 #undef time
 
 #include <ft2build.h>
-#include <freetype/config/ftheader.h>
 #include FT_FREETYPE_H
 #include FT_GLYPH_H
 

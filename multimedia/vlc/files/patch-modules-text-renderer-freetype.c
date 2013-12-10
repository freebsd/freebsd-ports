--- modules/text_renderer/freetype.c.orig	2013-12-10 00:16:07.000000000 +0100
+++ modules/text_renderer/freetype.c	2013-12-10 00:20:55.000000000 +0100
@@ -90,10 +90,11 @@
 #endif
 
 /* Freetype */
-#include <freetype/ftsynth.h>
+#include <ft2build.h>
 #include FT_FREETYPE_H
 #include FT_GLYPH_H
 #include FT_STROKER_H
+#include FT_SYNTHESIS_H
 
 #define FT_FLOOR(X)     ((X & -64) >> 6)
 #define FT_CEIL(X)      (((X + 63) & -64) >> 6)

--- filter/subtitler/load_font.c.orig	2013-12-28 11:40:29.000000000 -0800
+++ filter/subtitler/load_font.c	2013-12-28 10:44:23.000000000 -0800
@@ -48,7 +48,7 @@
 #include <ft2build.h>
 #include FT_FREETYPE_H
 
-#include <freetype/ftglyph.h>
+#include <freetype2/ftglyph.h>
 
 /**
  * @file bswap.h


--- libvo/font_load_ft.c.orig	Tue Mar 16 21:33:42 2004
+++ libvo/font_load_ft.c	Tue Mar 16 21:34:02 2004
@@ -20,7 +20,8 @@
 
 #include <iconv.h>
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <freetype/ftglyph.h>
 
 #include "../bswap.h"

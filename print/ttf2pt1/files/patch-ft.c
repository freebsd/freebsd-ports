--- ft.c.orig	2003-12-31 22:30:50.000000000 +0100
+++ ft.c	2013-12-16 16:50:37.000000000 +0100
@@ -12,11 +12,12 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <sys/types.h>
-#include <freetype/freetype.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftsnames.h>
-#include <freetype/ttnameid.h>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_GLYPH_H
+#include FT_SFNT_NAMES_H
+#include FT_TRUETYPE_IDS_H
+#include FT_OUTLINE_H
 #include "pt1.h"
 #include "global.h"
 

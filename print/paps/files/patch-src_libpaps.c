--- src/libpaps.c.orig	2013-12-16 16:10:33.000000000 +0100
+++ src/libpaps.c	2013-12-16 16:11:06.000000000 +0100
@@ -25,8 +25,9 @@
 
 #include <pango/pango.h>
 #include <pango/pangoft2.h>
-#include <freetype/ftglyph.h>
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
 #include <errno.h>
 #include <stdlib.h>
 #include <stdio.h>

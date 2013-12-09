--- libgnomeprint/gnome-rfont.c.orig	2013-12-06 19:28:40.000000000 +0100
+++ libgnomeprint/gnome-rfont.c	2013-12-06 19:29:56.000000000 +0100
@@ -27,9 +27,8 @@
 #include <string.h>
 
 #include <ft2build.h>
-#include FT_FREETYPE_H
-#include <freetype/ftglyph.h>
-#include <freetype/ftbbox.h>
+#include FT_GLYPH_H
+#include FT_BBOX_H
 #include <libart_lgpl/art_misc.h>
 #include <libart_lgpl/art_affine.h>
 #include <libart_lgpl/art_vpath.h>

--- libavfilter/vf_drawtext.c.orig	2013-11-20 03:28:56.000000000 +0100
+++ libavfilter/vf_drawtext.c	2013-12-06 18:26:57.000000000 +0100
@@ -48,7 +48,6 @@
 #include "video.h"
 
 #include <ft2build.h>
-#include <freetype/config/ftheader.h>
 #include FT_FREETYPE_H
 #include FT_GLYPH_H
 #if CONFIG_FONTCONFIG

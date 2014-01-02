--- libavfilter/vf_drawtext.c.orig	2014-01-01 12:39:17.000000000 +0100
+++ libavfilter/vf_drawtext.c	2014-01-01 12:39:32.000000000 +0100
@@ -47,7 +47,6 @@
 #include "video.h"
 
 #include <ft2build.h>
-#include <freetype/config/ftheader.h>
 #include FT_FREETYPE_H
 #include FT_GLYPH_H
 

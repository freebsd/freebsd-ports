--- libvo/font_load.h.orig	Tue Mar 16 21:29:40 2004
+++ libvo/font_load.h	Tue Mar 16 21:29:58 2004
@@ -2,7 +2,8 @@
 #define __MPLAYER_FONT_LOAD_H
 
 #ifdef HAVE_FREETYPE
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #endif
 
 typedef struct {

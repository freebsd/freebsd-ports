--- src/xftglyphs.c.orig	2012-06-02 18:36:35.000000000 +0200
+++ src/xftglyphs.c	2013-12-05 16:57:20.000000000 +0100
@@ -21,10 +21,11 @@
  */
 
 #include "xftint.h"
-#include <freetype/ftoutln.h>
-#include <freetype/ftlcdfil.h>
 
-#include <freetype/ftsynth.h>
+#include <ft2build.h>
+#include FT_OUTLINE_H
+#include FT_LCD_FILTER_H
+#include FT_SYNTHESIS_H
 
 /*
  * Validate the memory info for a font

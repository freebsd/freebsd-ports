--- src/fapi_ft.c.orig	Sat Dec 13 07:07:59 2003
+++ src/fapi_ft.c	Wed Mar 17 21:43:43 2004
@@ -30,7 +30,8 @@
 #include "math_.h"
 
 /* FreeType headers */
-#include "freetype/freetype.h"
+#include "ft2build.h"
+#include FT_FREETYPE_H
 #include "freetype/ftincrem.h"
 #include "freetype/ftglyph.h"
 #include "freetype/ftoutln.h"

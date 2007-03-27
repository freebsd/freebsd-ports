--- src/fapi_ft.c.orig	Mon Mar 13 17:18:19 2006
+++ src/fapi_ft.c	Sun Mar 18 16:23:21 2007
@@ -26,11 +26,14 @@
 #include "math_.h"
 
 /* FreeType headers */
-#include "freetype/freetype.h"
+#include "ft2build.h"
+#include FT_FREETYPE_H
 #include "freetype/ftincrem.h"
 #include "freetype/ftglyph.h"
 #include "freetype/ftoutln.h"
 #include "freetype/fttrigon.h"
+#include "gserrors.h"
+#include "gserror.h"
 
 /* Note: structure definitions here start with FF_, which stands for 'FAPI FreeType". */
 

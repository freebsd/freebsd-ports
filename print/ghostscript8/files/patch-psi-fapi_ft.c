--- psi/fapi_ft.c.orig	Wed Jul 11 09:26:24 2007
+++ psi/fapi_ft.c	Fri Aug 10 02:40:41 2007
@@ -28,11 +28,14 @@
 #include "gserror.h"
 
 /* FreeType headers */
-#include "freetype/freetype.h"
-#include "freetype/ftincrem.h"
-#include "freetype/ftglyph.h"
-#include "freetype/ftoutln.h"
-#include "freetype/fttrigon.h"
+#include "ft2build.h"
+#include FT_FREETYPE_H
+#include FT_INCREMENTAL_H
+#include FT_GLYPH_H
+#include FT_OUTLINE_H
+#include FT_TRIGONOMETRY_H
+#include "gserrors.h"
+#include "gserror.h"
 
 /* Note: structure definitions here start with FF_, which stands for 'FAPI FreeType". */
 

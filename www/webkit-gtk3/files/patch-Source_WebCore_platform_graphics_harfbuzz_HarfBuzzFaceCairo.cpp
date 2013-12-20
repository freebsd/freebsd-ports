--- Source/WebCore/platform/graphics/harfbuzz/HarfBuzzFaceCairo.cpp.orig	2013-12-08 21:05:19.000000000 +0100
+++ Source/WebCore/platform/graphics/harfbuzz/HarfBuzzFaceCairo.cpp	2013-12-08 21:06:51.000000000 +0100
@@ -39,8 +39,9 @@
 #include "TextEncoding.h"
 #include <cairo-ft.h>
 #include <cairo.h>
-#include <freetype/freetype.h>
-#include <freetype/tttables.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
+#include FT_TRUETYPE_TABLES_H
 #include <hb.h>
 #include <wtf/text/CString.h>
 

--- lib/video/sub_ft.cpp.orig	Wed Mar 17 15:25:55 2004
+++ lib/video/sub_ft.cpp	Wed Mar 17 15:26:49 2004
@@ -6,7 +6,8 @@
 
 #ifdef HAVE_LIBFREETYPE
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 #if (FREETYPE_MAJOR > 2) || (FREETYPE_MAJOR == 2 && FREETYPE_MINOR >= 1)
 #define HAVE_FREETYPE21

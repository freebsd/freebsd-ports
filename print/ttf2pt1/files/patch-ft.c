--- ft.c.orig	Sun Mar 21 18:24:06 2004
+++ ft.c	Sun Mar 21 18:24:31 2004
@@ -12,7 +12,8 @@
 #include <stdlib.h>
 #include <ctype.h>
 #include <sys/types.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <freetype/ftglyph.h>
 #include <freetype/ftsnames.h>
 #include <freetype/ttnameid.h>

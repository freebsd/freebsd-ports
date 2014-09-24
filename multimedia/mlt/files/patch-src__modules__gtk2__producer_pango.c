--- src/modules/gtk2/producer_pango.c.orig	2014-06-29 20:23:17 UTC
+++ src/modules/gtk2/producer_pango.c
@@ -25,7 +25,8 @@
 #include <string.h>
 #include <gdk-pixbuf/gdk-pixbuf.h>
 #include <pango/pangoft2.h>
-#include <freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <iconv.h>
 #include <pthread.h>
 #include <ctype.h>

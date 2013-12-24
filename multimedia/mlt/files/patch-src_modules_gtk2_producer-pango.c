--- src/modules/gtk2/producer_pango.c.orig	2013-12-24 21:37:38.000000000 +0100
+++ src/modules/gtk2/producer_pango.c	2013-12-24 21:37:11.000000000 +0100
@@ -25,7 +25,8 @@
 #include <string.h>
 #include <gdk-pixbuf/gdk-pixbuf.h>
 #include <pango/pangoft2.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <iconv.h>
 #include <pthread.h>
 #include <ctype.h>

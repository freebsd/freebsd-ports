--- src/gdiplus-private.h.orig	2013-12-17 00:22:34.000000000 +0100
+++ src/gdiplus-private.h	2013-12-17 00:23:00.000000000 +0100
@@ -30,7 +30,8 @@
 #include <stdio.h>
 #include <math.h>
 #include <glib.h>
-#include <freetype/tttables.h>
+#include <ft2build.h>
+#include FT_TRUETYPE_TABLES_H
 #include <pthread.h>
 #include <unistd.h>
 

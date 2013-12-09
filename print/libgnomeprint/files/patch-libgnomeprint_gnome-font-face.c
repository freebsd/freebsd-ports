--- libgnomeprint/gnome-font-face.c.orig	2013-12-06 19:26:26.000000000 +0100
+++ libgnomeprint/gnome-font-face.c	2013-12-06 19:27:43.000000000 +0100
@@ -36,7 +36,8 @@
 #include <stdarg.h>
 #include <locale.h>
 
-#include <freetype/ftoutln.h>
+#include <ft2build.h>
+#include FT_OUTLINE_H
 
 #include <libgnomeprint/gnome-print-private.h>
 #include <libgnomeprint/gnome-font-private.h>

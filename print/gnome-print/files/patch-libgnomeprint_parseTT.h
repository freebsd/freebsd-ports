--- libgnomeprint/parseTT.h.orig	Mon Mar 22 23:30:50 2004
+++ libgnomeprint/parseTT.h	Mon Mar 22 23:31:05 2004
@@ -22,7 +22,8 @@
 BEGIN_GNOME_DECLS
 
 #include <glib.h>
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 
 /*
  * Convert loaded Freetype TTF face to Type1

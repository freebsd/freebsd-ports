--- libgnomeprint/gnome-font-private.h.orig	Mon Mar 22 23:31:37 2004
+++ libgnomeprint/gnome-font-private.h	Mon Mar 22 23:31:52 2004
@@ -22,7 +22,8 @@
 
 BEGIN_GNOME_DECLS
 
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <libgnomeprint/gp-character-block.h>
 #include <libgnomeprint/gp-fontmap.h>
 #include <libgnomeprint/gnome-font.h>

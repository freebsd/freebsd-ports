--- installer/gnome-font-install.c.orig	Mon Mar 22 23:32:31 2004
+++ installer/gnome-font-install.c	Mon Mar 22 23:32:44 2004
@@ -26,7 +26,8 @@
 #include <parser.h>
 #include <xmlmemory.h>
 /* End of ugly thing */
-#include <freetype/freetype.h>
+#include <ft2build.h>
+#include FT_FREETYPE_H
 #include <libgnome/gnome-defs.h>
 #include <libgnome/gnome-util.h>
 #include <libgnome/gnome-i18n.h>

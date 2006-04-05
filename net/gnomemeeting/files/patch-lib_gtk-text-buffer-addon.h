--- lib/gtk-text-buffer-addon.h.orig	Sun Mar 13 15:13:36 2005
+++ lib/gtk-text-buffer-addon.h	Sun Mar 13 15:14:07 2005
@@ -40,7 +40,7 @@
 
 #include <gtk/gtk.h>
 #include <string.h>
-
+#include <unistd.h>
 
 #ifndef __GTK_TEXT_BUF_ADD_H
 #define __GTK_TEXT_BUF_ADD_H

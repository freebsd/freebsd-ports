--- player/app/gtk/uri_interface.c.orig	Fri May 14 20:49:15 2004
+++ player/app/gtk/uri_interface.c	Fri May 21 23:20:47 2004
@@ -12,6 +12,10 @@
 #include <string.h>
 #include <stdio.h>
 
+#ifdef GTK_DISABLE_DEPRECATED
+# undef GTK_DISABLE_DEPRECATED
+#endif
+
 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtk.h>
 

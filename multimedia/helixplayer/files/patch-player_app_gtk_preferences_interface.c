--- player/app/gtk/preferences_interface.c.orig	Mon May 17 23:18:17 2004
+++ player/app/gtk/preferences_interface.c	Fri May 21 23:18:33 2004
@@ -12,6 +12,10 @@
 #include <string.h>
 #include <stdio.h>
 
+#ifdef GTK_DISABLE_DEPRECATED
+# undef GTK_DISABLE_DEPRECATED
+#endif
+
 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtk.h>
 

--- player/app/gtk/statistics_interface.c.orig	Tue May  4 18:30:10 2004
+++ player/app/gtk/statistics_interface.c	Fri May 21 23:26:07 2004
@@ -12,6 +12,10 @@
 #include <string.h>
 #include <stdio.h>
 
+#ifdef GTK_DISABLE_DEPRECATED
+# undef GTK_DISABLE_DEPRECATED
+#endif
+
 #include <gdk/gdkkeysyms.h>
 #include <gtk/gtk.h>
 

--- src/callbacks.c.orig	Sun Nov 17 21:18:28 2002
+++ src/callbacks.c	Sun Nov 17 21:19:26 2002
@@ -14,7 +14,8 @@
 #include <dirent.h>
 #include <gdk/gdkkeysyms.h>
 #include <gdk/gdk.h>
-#include <linux/sem.h>
+#include <sys/ipc.h>
+#include <sys/sem.h>
 #include <gnome.h>
 #include <glib.h>
 #include <time.h>

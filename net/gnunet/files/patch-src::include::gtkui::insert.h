--- src/include/gtkui/insert.h.orig	Mon Aug 12 02:48:18 2002
+++ src/include/gtkui/insert.h	Sat Aug 17 13:14:07 2002
@@ -26,6 +26,7 @@
 #define GTKUI_INSERT_H
 
 #include "config.h"
+#include <pthread.h>
 #include <gtk/gtk.h>
 #include <glib.h>
 

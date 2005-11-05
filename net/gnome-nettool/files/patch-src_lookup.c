--- src/lookup.c.orig	Sun Jul  3 17:47:02 2005
+++ src/lookup.c	Sun Jul  3 17:47:20 2005
@@ -21,6 +21,7 @@
 #include <gtk/gtk.h>
 #include <glib/gi18n.h>
 #include <glib/gprintf.h>
+#include <sys/types.h>
 
 #include "lookup.h"
 #include "utils.h"

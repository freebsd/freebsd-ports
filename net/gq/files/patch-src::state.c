--- src/state.c.orig	2008-01-09 16:35:12.000000000 +0000
+++ src/state.c	2013-03-06 13:32:20.000000000 +0000
@@ -36,7 +36,7 @@
 #include <errno.h>
 
 #include <glib/gi18n.h>
-#include <glib/gmessages.h>
+#include <glib.h>
 #include <gtk/gtk.h>
 
 #include "configfile.h"
@@ -806,7 +806,7 @@
 	}
     }
 
-    if (n != NULL && v->type != 0) {
+    if (n != NULL && v!=NULL && v->type != 0) {
 	char *ep;
 
 	g_assert(v);

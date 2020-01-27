--- src/state.c.orig	2008-01-09 16:35:12 UTC
+++ src/state.c
@@ -36,7 +36,7 @@
 #include <errno.h>
 
 #include <glib/gi18n.h>
-#include <glib/gmessages.h>
+#include <glib.h>
 #include <gtk/gtk.h>
 
 #include "configfile.h"
@@ -806,7 +806,7 @@ static void state_valueE(struct parser_context *ctx,
 	}
     }
 
-    if (n != NULL && v->type != 0) {
+    if (n != NULL && v!=NULL && v->type != 0) {
 	char *ep;
 
 	g_assert(v);

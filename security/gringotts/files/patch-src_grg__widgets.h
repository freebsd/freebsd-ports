--- src/grg_widgets.h.orig	2008-01-04 13:08:43 UTC
+++ src/grg_widgets.h
@@ -25,7 +25,7 @@
 #include "grg_defs.h"
 #include <gtk/gtk.h>
 
-gboolean mapIsUTF;
+extern gboolean mapIsUTF;
 
 /* Shows and manages a dialog that asks for a string. */
 gchar *grg_input_dialog (gchar * title, gchar * qtext, gchar * preset,

--- src/grg_attachs.h.orig	2008-01-04 13:08:44 UTC
+++ src/grg_attachs.h
@@ -24,7 +24,7 @@
 
 #include <gtk/gtk.h>
 
-gint current_attach_ID;
+extern gint current_attach_ID;
 
 gint grg_attach_file (gchar * path, GtkWidget * parent);
 void grg_remove_attachment (void);

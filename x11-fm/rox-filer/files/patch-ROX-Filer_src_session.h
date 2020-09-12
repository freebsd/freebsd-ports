--- ROX-Filer/src/session.h.orig	2020-09-12 22:44:37 UTC
+++ ROX-Filer/src/session.h
@@ -10,7 +10,7 @@
 #include <gtk/gtk.h>
 #include <X11/SM/SMlib.h>
 
-gboolean session_auto_respawn;
+extern gboolean session_auto_respawn;
 
 void session_init(const gchar *client_id);
 

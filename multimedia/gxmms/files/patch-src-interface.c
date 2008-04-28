--- src/interface.c.orig	2008-04-24 15:30:43.000000000 +0200
+++ src/interface.c	2008-04-24 15:31:31.000000000 +0200
@@ -224,7 +224,7 @@
     gdouble width;
     GtkWidget *progress;
     BonoboUIComponent *popup;
-    gchar info[256] = _("No track");
+    gchar info[256] = "No track";
 
     progress = xmms->track_control.progress;
     if (!xmms_remote_is_running(xmms->session))

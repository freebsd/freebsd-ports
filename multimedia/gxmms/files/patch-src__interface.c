--- ./src/interface.c.orig	2005-01-05 01:22:54.000000000 +0100
+++ ./src/interface.c	2013-03-09 11:13:27.000000000 +0100
@@ -227,7 +227,7 @@
     gdouble width;
     GtkWidget *progress;
     BonoboUIComponent *popup;
-    gchar info[256] = _("No track");
+    gchar info[256] = "No track";
 
     progress = xmms->track_control.progress;
     if (!player_is_running(xmms))

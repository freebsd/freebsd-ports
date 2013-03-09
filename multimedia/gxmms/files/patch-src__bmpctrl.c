--- ./src/bmpctrl.c.orig	2004-12-30 01:24:11.000000000 +0100
+++ ./src/bmpctrl.c	2013-03-09 11:13:54.000000000 +0100
@@ -44,7 +44,7 @@
 void
 player_start(XMMSData *xmms)
 {
-    static gchar *msg_error = _("Unable to launch Beep Media Player.");
+    gchar *msg_error = _("Unable to launch Beep Media Player.");
     static gchar *exec_cmd = "beep-media-player &";
     gint timer;
     time_t lt;

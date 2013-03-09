--- ./src/xmmsctrl.c.orig	2005-01-05 01:22:54.000000000 +0100
+++ ./src/xmmsctrl.c	2013-03-09 11:13:27.000000000 +0100
@@ -44,11 +44,11 @@
 void
 player_start(XMMSData *xmms)
 {
-    static gchar *msg_error = _("Unable to launch XMMS.");
-    static gchar *exec_cmd = "xmms &";
+    gchar *msg_error = _("Unable to launch XMMS.");
+    gchar *exec_cmd = "xmms &";
     gint timer;
     time_t lt;
-
+    	
     if (player_is_running(xmms))
     {
         return;

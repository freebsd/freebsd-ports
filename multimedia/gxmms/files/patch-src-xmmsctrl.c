--- src/xmmsctrl.c.orig	2004-09-03 00:19:54.000000000 +0200
+++ src/xmmsctrl.c	2008-04-24 15:36:57.000000000 +0200
@@ -45,16 +45,17 @@
 xmms_start(XMMSData *xmms)
 {
     static gchar *exec_cmd = "xmms";
-    static gchar *msg_error = _("Sorry, unable to launch XMMS.");
+    gchar *msg_error = _("Sorry, unable to launch XMMS.");
     gint timer;
     time_t lt;
+    gchar *exec_this;
 
     if (xmms_remote_is_running(xmms->session))
     {
         return;
     }
 
-    gchar *exec_this = g_strdup_printf("%s &", exec_cmd);
+    exec_this = g_strdup_printf("%s &", exec_cmd);
 
     if (system(exec_this))
     {

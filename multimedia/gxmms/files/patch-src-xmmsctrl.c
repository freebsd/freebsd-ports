--- src/xmmsctrl.c.orig	Fri Sep  3 00:19:54 2004
+++ src/xmmsctrl.c	Thu Nov  4 14:36:56 2004
@@ -48,13 +48,14 @@
     static gchar *msg_error = _("Sorry, unable to launch XMMS.");
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

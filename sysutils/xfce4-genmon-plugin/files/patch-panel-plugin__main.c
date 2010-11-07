--- ./panel-plugin/main.c.orig	2008-03-15 23:38:18.000000000 +0100
+++ ./panel-plugin/main.c	2010-11-07 11:28:17.000000000 +0100
@@ -32,6 +32,7 @@
 
 #include <libxfce4util/libxfce4util.h>
 #include <libxfcegui4/dialogs.h>
+#include <libxfcegui4/xfce-exec.h>
 #include <libxfce4panel/xfce-panel-plugin.h>
 #include <libxfce4panel/xfce-panel-convenience.h>
 
@@ -94,10 +95,18 @@
 {
     struct genmon_t *poPlugin = (genmon_t *) p_pvPlugin;
     struct monitor_t *poMonitor = &(poPlugin->oMonitor);
-    char result[256];
+    GError *error = NULL;
+
+	xfce_exec(poMonitor->onClickCmd, 0, 0, &error);
+    if (error) {
+        char first[256];
+        g_snprintf (first, sizeof(first), _("Could not run \"%s\""), poMonitor->onClickCmd);
+        xfce_message_dialog (NULL, _("Xfce Panel"), 
+                             GTK_STOCK_DIALOG_ERROR, first, error->message,
+                             GTK_STOCK_CLOSE, GTK_RESPONSE_OK, NULL);
+        g_error_free (error);
+    }
 
-    genmon_SpawnCmd (poMonitor->onClickCmd, result,
-        sizeof (poMonitor->onClickCmd), 0);
 }
 
 /**************************************************************/

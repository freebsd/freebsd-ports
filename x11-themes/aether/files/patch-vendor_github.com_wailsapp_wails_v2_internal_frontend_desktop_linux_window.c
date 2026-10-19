--- vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/window.c.orig	2026-09-29 13:40:03 UTC
+++ vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/window.c
@@ -141,7 +141,7 @@ static int getCurrentMonitorScaleFactor(GtkWindow *win
 
 // window
 
-ulong SetupInvokeSignal(void *contentManager)
+unsigned long SetupInvokeSignal(void *contentManager)
 {
     return g_signal_connect((WebKitUserContentManager *)contentManager, "script-message-received::external", G_CALLBACK(sendMessageToBackend), NULL);
 }

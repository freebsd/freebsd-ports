--- vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/window.h.orig	2026-09-29 13:40:03 UTC
+++ vendor/github.com/wailsapp/wails/v2/internal/frontend/desktop/linux/window.h
@@ -80,7 +80,7 @@ GtkBox *GTKBOX(void *pointer);
 GtkBox *GTKBOX(void *pointer);
 
 // window
-ulong SetupInvokeSignal(void *contentManager);
+unsigned long SetupInvokeSignal(void *contentManager);
 
 void SetWindowIcon(GtkWindow *window, const guchar *buf, gsize len);
 void SetWindowTransparency(GtkWidget *widget);

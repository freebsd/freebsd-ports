--- Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.h.orig	2021-04-14 05:42:51 UTC
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.h
@@ -11,9 +11,9 @@
 extern "C" {
 #undef signals
 #include <JavaScriptCore/JavaScript.h>
+#include <gdk/gdkx.h>
 #include <gtk/gtk.h>
 #include <webkit2/webkit2.h>
-#include <X11/Xlib.h>
 #define signals public
 } // extern "C"
 

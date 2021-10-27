--- Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.h.orig	2021-07-07 09:00:15 UTC
+++ Telegram/lib_webview/webview/platform/linux/webview_linux_webkit_gtk.h
@@ -6,6 +6,7 @@
 //
 #pragma once
 
+#include <type_traits>  // Required for glib/gatomic.h
 #include <JavaScriptCore/JavaScript.h>
 #include <gtk/gtk.h>
 #include <webkit2/webkit2.h>

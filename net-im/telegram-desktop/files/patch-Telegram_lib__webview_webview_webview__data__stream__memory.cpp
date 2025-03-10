--- Telegram/lib_webview/webview/webview_data_stream_memory.cpp.orig	2025-02-13 17:00:08 UTC
+++ Telegram/lib_webview/webview/webview_data_stream_memory.cpp
@@ -8,6 +8,7 @@
 
 #if !defined Q_OS_WIN && !defined Q_OS_MAC
 #include <sys/mman.h>
+#include <unistd.h>
 #endif // !Q_OS_WIN && !Q_OS_MAC
 
 namespace Webview {

--- native/temp_window.h.orig	2026-09-08 14:07:06 UTC
+++ native/temp_window.h
@@ -8,7 +8,7 @@
 
 #if defined(OS_WIN)
 #include "temp_window_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "temp_window_x11.h"
 #elif defined(OS_MACOSX)
 #include "temp_window_mac.h"
@@ -16,7 +16,7 @@ typedef TempWindowWin TempWindow;
 
 #if defined(OS_WIN)
 typedef TempWindowWin TempWindow;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 typedef TempWindowX11 TempWindow;
 #elif defined(OS_MACOSX)
 typedef TempWindowMac TempWindow;

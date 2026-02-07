--- pdf_viewer/utils.cpp.orig	2025-05-13 14:36:40 UTC
+++ pdf_viewer/utils.cpp
@@ -1548,7 +1548,7 @@ void sleep_ms(unsigned int ms) {
 #ifdef Q_OS_WIN
     Sleep(ms);
 #else
-    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
+    struct timespec ts = { static_cast<time_t>(ms / 1000), static_cast<long>((ms % 1000) * 1000 * 1000) };
     nanosleep(&ts, NULL);
 #endif
 }

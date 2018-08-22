--- Telegram/SourceFiles/platform/platform_audio.h.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/platform/platform_audio.h
@@ -19,7 +19,7 @@ void DeInit();
 
 // Platform dependent implementations.
 
-#if defined Q_OS_MAC || defined Q_OS_LINUX
+#if defined Q_OS_MAC || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 namespace Platform {
 namespace Audio {
 
@@ -31,6 +31,6 @@ inline void DeInit() {
 
 } // namespace Audio
 } // namespace Platform
-#elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WINRT || defined Q_OS_WIN // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 #include "platform/win/audio_win.h"
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_WIN
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_WIN || Q_OS_FREEBSD

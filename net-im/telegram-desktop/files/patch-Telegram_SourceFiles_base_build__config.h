--- Telegram/SourceFiles/base/build_config.h.orig	2019-02-01 12:51:46 UTC
+++ Telegram/SourceFiles/base/build_config.h
@@ -13,7 +13,7 @@ https://github.com/telegramdesktop/tdesktop/blob/maste
 
 #if defined(__APPLE__)
 #define OS_MAC 1
-#elif defined(__linux__) // __APPLE__
+#elif defined(__linux__) || defined(__FreeBSD__) // __APPLE__
 #define OS_LINUX 1
 #elif defined(_WIN32) // __APPLE__ || __linux__
 #define OS_WIN 1

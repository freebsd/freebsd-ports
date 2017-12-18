--- Telegram/SourceFiles/base/build_config.h.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/base/build_config.h
@@ -26,7 +26,7 @@ Copyright (c) 2014-2017 John Preston, ht
 
 #if defined(__APPLE__)
 #define OS_MAC 1
-#elif defined(__linux__) // __APPLE__
+#elif defined(__linux__) || defined(__FreeBSD__)// __APPLE__
 #define OS_LINUX 1
 #elif defined(_WIN32) // __APPLE__ || __linux__
 #define OS_WIN 1

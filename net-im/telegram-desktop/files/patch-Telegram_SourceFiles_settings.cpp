--- Telegram/SourceFiles/settings.cpp.orig	2018-12-24 08:16:05 UTC
+++ Telegram/SourceFiles/settings.cpp
@@ -77,6 +77,8 @@ DBIPlatform gPlatform = dbipMac;
 DBIPlatform gPlatform = dbipLinux64;
 #elif defined Q_OS_LINUX32
 DBIPlatform gPlatform = dbipLinux32;
+#elif defined Q_OS_FREEBSD
+DBIPlatform gPlatform = dbipFreeBSD;
 #else
 #error Unknown platform
 #endif

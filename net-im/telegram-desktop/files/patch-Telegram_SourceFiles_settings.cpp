--- Telegram/SourceFiles/settings.cpp.orig	2018-02-06 06:26:16 UTC
+++ Telegram/SourceFiles/settings.cpp
@@ -83,6 +83,8 @@ DBIPlatform gPlatform = dbipMac;
 DBIPlatform gPlatform = dbipLinux64;
 #elif defined Q_OS_LINUX32
 DBIPlatform gPlatform = dbipLinux32;
+#elif defined Q_OS_FREEBSD
+DBIPlatform gPlatform = dbipFreeBSD;
 #else
 #error Unknown platform
 #endif

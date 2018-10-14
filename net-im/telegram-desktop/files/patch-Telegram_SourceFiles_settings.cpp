--- Telegram/SourceFiles/settings.cpp.orig	2018-10-09 21:21:48 UTC
+++ Telegram/SourceFiles/settings.cpp
@@ -79,6 +79,8 @@ DBIPlatform gPlatform = dbipMac;
 DBIPlatform gPlatform = dbipLinux64;
 #elif defined Q_OS_LINUX32
 DBIPlatform gPlatform = dbipLinux32;
+#elif defined Q_OS_FREEBSD
+DBIPlatform gPlatform = dbipFreeBSD;
 #else
 #error Unknown platform
 #endif

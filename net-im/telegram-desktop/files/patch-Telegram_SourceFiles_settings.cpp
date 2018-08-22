--- Telegram/SourceFiles/settings.cpp.orig	2018-08-04 18:53:40 UTC
+++ Telegram/SourceFiles/settings.cpp
@@ -81,6 +81,8 @@ DBIPlatform gPlatform = dbipMac;
 DBIPlatform gPlatform = dbipLinux64;
 #elif defined Q_OS_LINUX32
 DBIPlatform gPlatform = dbipLinux32;
+#elif defined Q_OS_FREEBSD
+DBIPlatform gPlatform = dbipFreeBSD;
 #else
 #error Unknown platform
 #endif

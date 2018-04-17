--- Telegram/SourceFiles/config.h.orig	2018-04-08 17:34:33 UTC
+++ Telegram/SourceFiles/config.h
@@ -240,7 +240,7 @@ inline const char *cApiDeviceModel() {
 	return "PC";
 #elif defined Q_OS_MAC
 	return "Mac";
-#elif defined Q_OS_LINUX
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	return "PC";
 #endif
 }
@@ -251,6 +251,8 @@ inline const char *cApiSystemVersion() {
 	return "OS X";
 #elif defined Q_OS_LINUX
 	return "Linux";
+#elif defined Q_OS_FREEBSD
+	return "FreeBSD";
 #endif
 }
 

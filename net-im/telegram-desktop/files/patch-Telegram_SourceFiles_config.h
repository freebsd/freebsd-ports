--- Telegram/SourceFiles/config.h.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/config.h
@@ -270,7 +270,7 @@ inline const char *cApiDeviceModel() {
 	return "PC";
 #elif defined Q_OS_MAC
 	return "Mac";
-#elif defined Q_OS_LINUX
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	return "PC";
 #endif
 }
@@ -281,6 +281,8 @@ inline const char *cApiSystemVersion() {
 	return "OS X";
 #elif defined Q_OS_LINUX
 	return "Linux";
+#elif defined Q_OS_FREEBSD
+	return "FreeBSD";
 #endif
 }
 

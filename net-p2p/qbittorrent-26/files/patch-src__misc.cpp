--- src/misc.cpp.orig	2011-01-06 04:12:07.000000000 -0800
+++ src/misc.cpp	2011-01-09 23:11:01.000000000 -0800
@@ -60,7 +60,7 @@
 #endif
 
 #ifndef Q_WS_WIN
-#ifdef Q_WS_MAC
+#if defined Q_WS_MAC || defined(__FreeBSD__)
 #include <sys/param.h>
 #include <sys/mount.h>
 #else

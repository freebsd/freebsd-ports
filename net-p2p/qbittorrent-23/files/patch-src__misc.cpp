--- src/misc.cpp.orig	2010-03-20 12:38:21.000000000 -0700
+++ src/misc.cpp	2010-04-04 22:13:02.000000000 -0700
@@ -52,7 +52,7 @@
 #endif
 
 #ifndef Q_WS_WIN
-#ifdef Q_WS_MAC
+#if defined Q_WS_MAC || defined(__FreeBSD__)
 #include <sys/param.h>
 #include <sys/mount.h>
 #else

--- src/misc.h.orig	2009-10-01 03:44:58.000000000 +0900
+++ src/misc.h	2009-11-27 02:33:54.000000000 +0900
@@ -43,7 +43,7 @@
 #include <QThread>
 
 #ifndef Q_WS_WIN
-#ifdef Q_WS_MAC
+#if defined(Q_WS_MAC) || defined(__FreeBSD__)
   #include <sys/param.h>
   #include <sys/mount.h>
 #else

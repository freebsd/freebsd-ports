--- src/filesystemwatcher.h.orig	2009-12-11 04:39:09.000000000 +0900
+++ src/filesystemwatcher.h	2009-12-17 00:41:29.000000000 +0900
@@ -11,7 +11,7 @@
 #include <QSet>
 #include <iostream>
 #include <errno.h>
-#ifdef Q_WS_MAC
+#if defined(Q_WS_MAC) || defined(__FreeBSD__)
 #include <sys/param.h>
 #include <sys/mount.h>
 #else

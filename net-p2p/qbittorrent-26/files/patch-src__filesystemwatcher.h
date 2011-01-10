--- src/filesystemwatcher.h.orig	2011-01-07 11:42:34.000000000 -0800
+++ src/filesystemwatcher.h	2011-01-09 23:11:01.000000000 -0800
@@ -12,7 +12,7 @@
 #include <QSet>
 #include <iostream>
 #include <errno.h>
-#ifdef Q_WS_MAC
+#if defined(Q_WS_MAC) || defined(__FreeBSD__)
 #include <sys/param.h>
 #include <sys/mount.h>
 #include <string.h>

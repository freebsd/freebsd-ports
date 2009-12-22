--- src/misc.h.orig	2009-12-13 19:15:50.000000000 +0900
+++ src/misc.h	2009-12-17 00:34:12.000000000 +0900
@@ -47,7 +47,7 @@
 #include <boost/date_time/posix_time/conversion.hpp>
 
 #ifndef Q_WS_WIN
-#ifdef Q_WS_MAC
+#if defined(Q_WS_MAC) || defined(__FreeBSD__)
 #include <sys/param.h>
 #include <sys/mount.h>
 #else

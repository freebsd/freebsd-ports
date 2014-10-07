--- src/lib/3rdparty/processinfo.h.orig	2014-09-26 12:35:35.000000000 +0400
+++ src/lib/3rdparty/processinfo.h	2014-09-26 23:04:10.000000000 +0400
@@ -18,6 +18,8 @@
 #ifndef PROCESSINFO_H
 #define PROCESSINFO_H
 
+#include <QtGlobal>
+
 #if defined(Q_OS_UNIX) && !defined(Q_OS_MAC)
 #include <sys/types.h>
 #endif

--- libclamav/zziplib/zziplib.h.orig	Mon Sep 29 13:44:52 2003
+++ libclamav/zziplib/zziplib.h	Fri Oct  3 15:45:22 2003
@@ -19,6 +19,9 @@
 #ifndef _ZZIP_ZZIP_H /* zziplib.h */
 #define _ZZIP_ZZIP_H
 
+#ifdef __FreeBSD__
+#include <unistd.h>
+#endif
 #include <zzip-conf.h>
 
 #include <fcntl.h>

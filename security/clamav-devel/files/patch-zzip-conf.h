--- libclamav/zziplib/zzip-conf.h.orig	Mon Sep 29 13:44:52 2003
+++ libclamav/zziplib/zzip-conf.h	Fri Oct  3 15:24:20 2003
@@ -64,7 +64,7 @@
 #ifdef   ZZIP_ssize_t
 #define _zzip_ssize_t ZZIP_ssize_t
 #else
-#define _zzip_ssize_t ssize_t
+#define _zzip_ssize_t size_t
 #endif
 #endif
 

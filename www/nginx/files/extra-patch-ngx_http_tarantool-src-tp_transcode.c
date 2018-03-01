--- ../nginx_upstream_module-1278ee5/src/tp_transcode.c.orig	2016-08-08 03:39:47.000000000 +0800
+++ ../nginx_upstream_module-1278ee5/src/tp_transcode.c	2018-03-01 04:23:02.513740000 +0800
@@ -38,10 +38,6 @@
 #  define GNU_SOURCES 1
 #endif /* !GNU_SOURCES */
 
-#if !defined(MP_SOURCE)
-#  define MP_SOURCE 1
-#endif /* !MP_SOURCE */
-
 #include "tp_ext.h"
 #include "tp_transcode.h"
 

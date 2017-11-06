--- libhb/fifo.c.orig	2017-02-25 20:56:19 UTC
+++ libhb/fifo.c
@@ -13,7 +13,7 @@
 #include "qsv_libav.h"
 #endif
 
-#ifndef SYS_DARWIN
+#if !defined(SYS_DARWIN) && !defined(SYS_FREEBSD)
 #include <malloc.h>
 #endif
 

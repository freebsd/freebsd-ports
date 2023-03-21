--- dl.c.orig	2020-11-26 15:36:13 UTC
+++ dl.c
@@ -1,3 +1,6 @@
+#ifdef __FreeBSD__
+#include <stdio.h>
+#endif
 #define _FILE_OFFSET_BITS 64
 #define _GNU_SOURCE
 

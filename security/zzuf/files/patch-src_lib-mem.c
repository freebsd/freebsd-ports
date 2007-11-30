--- src/lib-mem.c.orig	Tue Feb 20 18:18:25 2007
+++ src/lib-mem.c	Mon Apr  9 12:45:22 2007
@@ -20,6 +20,8 @@
 
 /* Need this for RTLD_NEXT */
 #define _GNU_SOURCE
+/* Need this for MAP_ANON */
+#define __BSD_VISIBLE 1
 /* Use this to get mmap64() on glibc systems */
 #define _LARGEFILE64_SOURCE
 /* Use this to get posix_memalign */

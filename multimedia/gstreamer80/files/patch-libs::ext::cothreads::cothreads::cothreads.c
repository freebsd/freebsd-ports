--- libs/ext/cothreads/cothreads/cothreads.c.orig	Thu Nov 14 15:19:11 2002
+++ libs/ext/cothreads/cothreads/cothreads.c	Thu Nov 14 15:20:02 2002
@@ -21,6 +21,7 @@
 
 #include "pth_p.h" /* this pulls in everything */
 #include <sys/mman.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 
 /* older glibc's have MAP_ANON instead of MAP_ANONYMOUS */

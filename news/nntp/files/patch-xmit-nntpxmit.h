--- xmit/nntpxmit.h.orig	Thu Nov  3 04:51:34 1994
+++ xmit/nntpxmit.h	Sun Jan  9 09:30:04 2000
@@ -7,6 +7,7 @@
 */
 
 #ifdef MMAP
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <sys/stat.h>
 #endif

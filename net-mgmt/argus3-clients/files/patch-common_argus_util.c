--- common/argus_util.c~	2008-02-05 04:37:43.000000000 +0100
+++ common/argus_util.c	2008-02-07 11:32:41.604018124 +0100
@@ -100,6 +100,9 @@
 #ifndef AF_INET6
 #define AF_INET6	23
 #endif
+#if defined(__FreeBSD__) /* should work for NetBSD too */
+#include <sys/limits.h>
+#endif
 
 
 #ifndef INET6_ADDRSTRLEN

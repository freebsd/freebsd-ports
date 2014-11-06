--- lib/utils.h.orig	2014-06-05 02:25:50.000000000 -0400
+++ lib/utils.h	2014-07-27 01:48:52.000000000 -0400
@@ -3,6 +3,9 @@
 #ifndef CCNET_UTILS_H
 #define CCNET_UTILS_H
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <netinet/in.h>
+#endif
 #include <sys/time.h>
 #include <time.h>
 #include <stdint.h>

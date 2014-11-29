--- lib/utils.h.orig	2014-08-05 01:28:35.000000000 -0400
+++ lib/utils.h	2014-11-11 11:30:51.843637061 -0500
@@ -3,6 +3,9 @@
 #ifndef CCNET_UTILS_H
 #define CCNET_UTILS_H
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <netinet/in.h>
+#endif
 #include <sys/time.h>
 #include <time.h>
 #include <stdint.h>
@@ -13,7 +16,9 @@
 #include <stdlib.h>
 #include <sys/stat.h>
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__) 
+#include <evutil.h>
+#elif (__NetBSD__) || defined(__OpenBSD__)
 #include <event2/util.h>
 #else
 #include <evutil.h>

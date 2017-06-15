--- lib/utils.h.orig	2016-10-09 09:30:49 UTC
+++ lib/utils.h
@@ -10,6 +10,9 @@
 #include <windows.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <netinet/in.h>
+#endif
 #include <sys/time.h>
 #include <time.h>
 #include <stdint.h>
@@ -20,7 +23,9 @@
 #include <stdlib.h>
 #include <sys/stat.h>
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <evutil.h>
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
 #include <event2/util.h>
 #else
 #include <evutil.h>

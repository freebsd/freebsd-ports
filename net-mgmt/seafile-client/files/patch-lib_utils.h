--- lib/utils.h.orig	2022-04-25 10:27:18 UTC
+++ lib/utils.h
@@ -11,6 +11,10 @@
 #include <windows.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#include <netinet/in.h>
+#endif
+
 #ifndef WIN32
 #include <sys/time.h>
 #include <unistd.h>
@@ -23,7 +27,9 @@
 #include <stdlib.h>
 #include <sys/stat.h>
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <evutil.h>
+#elif defined(__NetBSD__) || defined(__OpenBSD__)
 #include <event2/util.h>
 #else
 #include <evutil.h>
@@ -33,7 +39,7 @@
 #include <endian.h>
 #endif
 
-#ifdef __OpenBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
 #include <machine/endian.h>
 #endif
 

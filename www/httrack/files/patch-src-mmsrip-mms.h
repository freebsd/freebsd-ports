--- src/mmsrip/mms.h.orig	Mon Jan 23 20:30:43 2006
+++ src/mmsrip/mms.h	Sat Jul 29 14:35:04 2006
@@ -46,7 +46,7 @@
 #endif
 typedef unsigned long long int uint64_t;
 #else
-#if defined(SOLARIS) || defined(sun)
+#if defined(SOLARIS) || defined(sun) || defined (__FreeBSD__)
 #include <inttypes.h>
 #else
 #include <stdint.h>

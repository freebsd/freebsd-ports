--- bytes.h.orig	2013-10-17 16:32:03.000000000 +0900
+++ bytes.h	2010-02-12 06:31:58.000000000 +0900
@@ -35,7 +35,7 @@
 
 typedef unsigned char uint8_t;
 
-#elif (defined(__FreeBSD__) && __FreeBSD_version >= 470000) || defined(__OpenBSD__) || defined(__NetBSD__) // *BSD
+#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) // *BSD
 #include <sys/endian.h>
 #define __BIG_ENDIAN    BIG_ENDIAN
 #define __LITTLE_ENDIAN LITTLE_ENDIAN

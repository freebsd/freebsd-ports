diff -Naur pri_q921.h.orig pri_q921.h
--- pri_q921.h.orig	2004-10-02 17:55:20.000000000 +0300
+++ pri_q921.h	2004-10-19 19:12:38.000000000 +0300
@@ -30,6 +30,9 @@
 #include <endian.h>
 #elif defined(__FreeBSD__)
 #include <sys/endian.h>
+#define __BYTE_ORDER _BYTE_ORDER
+#define __BIG_ENDIAN _BIG_ENDIAN
+#define __LITTLE_ENDIAN _LITTLE_ENDIAN
 #endif
 
 /* Timer values */

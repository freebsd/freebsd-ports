--- ../thotlib/base/fileaccess.c.orig	Fri Jul  4 21:35:35 2003
+++ ../thotlib/base/fileaccess.c	Wed Jul  9 19:45:40 2003
@@ -273,6 +273,18 @@
     unsigned int exponent:8;
     unsigned int mantissa:23;
 #else /*_WINDOWS*/
+#ifdef __FreeBSD__
+#if     BYTE_ORDER == BIG_ENDIAN
+    unsigned int negative:1;
+    unsigned int exponent:8;
+    unsigned int mantissa:23;
+#endif
+#if     BYTE_ORDER == LITTLE_ENDIAN
+    unsigned int mantissa:23;
+    unsigned int exponent:8;
+    unsigned int negative:1;
+#endif
+#else /*__FreeBSD__*/
 #if defined(i386) || defined(__i386)
 #if     __BYTE_ORDER == __BIG_ENDIAN
     unsigned int negative:1;
@@ -296,6 +308,7 @@
     unsigned int negative:1;
 #endif
 #endif
+#endif /*__FreeBSD__*/
 #endif /*_WINDOWS*/
   } ieee;
 };


$FreeBSD$

--- codecs/mp3/include/L3.h.orig	Wed Feb 12 15:59:14 2003
+++ codecs/mp3/include/L3.h	Fri Oct 17 11:27:30 2003
@@ -49,6 +49,14 @@
 #define LITTLE_ENDIAN 0
 #endif
 
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define LITTLE_ENDIAN 1
+#endif
+
+#if BYTE_ORDER == BIG_ENDIAN
+#define LITTLE_ENDIAN 0
+#endif
+
 #ifndef LITTLE_ENDIAN
 #error Layer III LITTLE_ENDIAN must be defined 0 or 1
 #endif

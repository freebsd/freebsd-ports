--- bytesex.h.orig	2003-08-31 17:23:48 UTC
+++ bytesex.h
@@ -7,6 +7,7 @@
 #ifndef ARS_BYTESEX_H
 #define ARS_BYTESEX_H
 
+#if 0
 #if 	defined(__i386__) \
 	|| defined(__alpha__) \
 	|| (defined(__mips__) && (defined(MIPSEL) || defined (__MIPSEL__)))
@@ -21,5 +22,12 @@
 #else
 # error can not find the byte order for this architecture, fix bytesex.h
 #endif
+#endif
+
+#if BYTE_ORDER == LITTLE_ENDIAN
+#define BYTE_ORDER_LITTLE_ENDIAN
+#else
+#define BYTE_ORDER_BIG_ENDIAN
+#endif
 
 #endif /* ARS_BYTESEX_H */

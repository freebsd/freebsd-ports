
$FreeBSD$

--- bytesex.h.orig	Tue Sep 14 15:22:45 2004
+++ bytesex.h	Tue Sep 14 15:21:50 2004
@@ -8,10 +8,12 @@
 #define ARS_BYTESEX_H
 
 #if 	defined(__i386__) \
+	|| defined(__ia64__) \
 	|| defined(__alpha__) \
 	|| (defined(__mips__) && (defined(MIPSEL) || defined (__MIPSEL__)))
 #define BYTE_ORDER_LITTLE_ENDIAN
 #elif 	defined(__mc68000__) \
+	|| defined (__amd64__) \
 	|| defined (__sparc__) \
 	|| defined (__sparc) \
 	|| defined (__PPC__) \

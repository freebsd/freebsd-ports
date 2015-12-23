--- bytesex.h.orig	2003-07-28 17:00:55.000000000 +0800
+++ bytesex.h	2015-12-22 22:30:11.367208000 +0800
@@ -8,10 +8,14 @@
 #define ARS_BYTESEX_H
 
 #if 	defined(__i386__) \
+	|| defined (__amd64__) \
+	|| defined(__ia64__) \
 	|| defined(__alpha__) \
+	|| defined(__arm__) \
 	|| (defined(__mips__) && (defined(MIPSEL) || defined (__MIPSEL__)))
 #define BYTE_ORDER_LITTLE_ENDIAN
 #elif 	defined(__mc68000__) \
+	|| (defined(__arm__) && (defined(ARMEB) || defined (__ARMEB__))) \
 	|| defined (__sparc__) \
 	|| defined (__sparc) \
 	|| defined (__PPC__) \

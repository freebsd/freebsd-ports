
$FreeBSD$

--- bytesex.h.orig	Sun May 30 00:12:35 2004
+++ bytesex.h	Sun May 30 00:15:29 2004
@@ -12,6 +12,7 @@
 	|| (defined(__mips__) && (defined(MIPSEL) || defined (__MIPSEL__)))
 #define BYTE_ORDER_LITTLE_ENDIAN
 #elif 	defined(__mc68000__) \
+	|| defined (__amd64__) \
 	|| defined (__sparc__) \
 	|| defined (__sparc) \
 	|| defined (__PPC__) \

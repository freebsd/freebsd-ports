--- src/common.h.orig	2012-11-12 01:29:34.000000000 +0900
+++ src/common.h	2012-12-05 16:43:09.000000000 +0900
@@ -756,7 +756,7 @@
  * warnings on a wrong __asm__ statement with glib 1.2.  This version
  * should be as efficient as the one defined by glib.
  */
-#if HAS_GCC(4, 0)
+#if HAS_GCC(4, 0) && !defined(__FreeBSD__)
 #define GUINT32_SWAP(x_) \
 	(IS_CONSTANT(x_) ? GUINT32_SWAP_CONSTANT(x_) : __builtin_bswap32(x_))
 #else

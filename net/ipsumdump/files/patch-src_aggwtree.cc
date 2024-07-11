--- src/aggwtree.cc.orig	2014-05-02 12:23:53 UTC
+++ src/aggwtree.cc
@@ -10,9 +10,11 @@
 #ifdef HAVE_BYTEORDER_H
 #include <byteorder.h>
 #else
+#if !defined(__powerpc64__) && !defined(POWERPC64)
 static inline uint32_t bswap_32(uint32_t u) {
     return ((u >> 24) | ((u & 0xff0000) >> 8) | ((u & 0xff00) << 8) | ((u & 0xff) << 24));
 }
+#endif
 #endif
 
 typedef AggregateWTree::WNode WNode;

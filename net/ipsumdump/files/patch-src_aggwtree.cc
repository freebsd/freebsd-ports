--- src/aggwtree.cc.orig	2024-06-01 22:57:44 UTC
+++ src/aggwtree.cc
@@ -9,10 +9,6 @@
 
 #ifdef HAVE_BYTEORDER_H
 #include <byteorder.h>
-#else
-static inline uint32_t bswap_32(uint32_t u) {
-    return ((u >> 24) | ((u & 0xff0000) >> 8) | ((u & 0xff00) << 8) | ((u & 0xff) << 24));
-}
 #endif
 
 typedef AggregateWTree::WNode WNode;

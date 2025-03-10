--- src/aggtree.cc.orig	2014-05-02 12:23:53 UTC
+++ src/aggtree.cc
@@ -11,9 +11,7 @@
 #ifdef HAVE_BYTEORDER_H
 #include <byteorder.h>
 #else
-static inline uint32_t bswap_32(uint32_t u) {
-    return ((u >> 24) | ((u & 0xff0000) >> 8) | ((u & 0xff00) << 8) | ((u & 0xff) << 24));
-}
+#include <byteswap.h>
 #endif
 
 

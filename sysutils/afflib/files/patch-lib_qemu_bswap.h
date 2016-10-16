--- lib/qemu/bswap.h.orig	2016-09-12 18:18:01 UTC
+++ lib/qemu/bswap.h
@@ -5,6 +5,9 @@
 
 #include <inttypes.h>
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #ifdef HAVE_BYTESWAP_H
 #include <byteswap.h>
 #else
@@ -57,6 +60,7 @@ static inline uint64_t bswap64(uint64_t 
 {
     return bswap_64(x);
 }
+#endif
 
 static inline void bswap16s(uint16_t *s)
 {

--- freebsd/include/dahdi/compat/bsd.h.orig	2010-10-05 23:41:23.000000000 +0700
+++ freebsd/include/dahdi/compat/bsd.h	2010-10-05 23:42:01.000000000 +0700
@@ -66,9 +66,11 @@
 #define __be32  u_int32_t
 
 #if _BYTE_ORDER == _LITTLE_ENDIAN
+#define __LITTLE_ENDIAN
 #define __LITTLE_ENDIAN_BITFIELD
 #define __constant_htons(x)	((uint16_t) (((uint16_t) (x)) << 8 | ((uint16_t) (x)) >> 8))
 #elif _BYTE_ORDER == _BIG_ENDIAN
+#define __BIG_ENDIAN
 #define __BIG_ENDIAN_BITFIELD
 #define __constant_htons(x)	(x)
 #endif

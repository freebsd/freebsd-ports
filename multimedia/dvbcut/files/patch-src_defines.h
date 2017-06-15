--- src/defines.h.orig	2016-11-18 13:31:01 UTC
+++ src/defines.h
@@ -42,6 +42,11 @@ static inline int videostream(int s=0)
 #endif
   }
 
+#ifdef __FreeBSD__
+#define __bswap_32(x) __bswap32(x)
+#define __bswap_16(x) __bswap16(x)
+#endif
+
 #if __BYTE_ORDER == __LITTLE_ENDIAN
 #define mbo32(x) \
       ((((x) & 0xff000000) >> 24) | (((x) & 0x00ff0000) >>  8) | \

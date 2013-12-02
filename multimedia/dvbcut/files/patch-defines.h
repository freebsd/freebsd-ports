--- src/defines.h~	2013-06-16 11:57:51.000000000 +0200
+++ src/defines.h	2013-11-29 22:35:26.867434652 +0100
@@ -42,6 +42,11 @@
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

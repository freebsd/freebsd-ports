--- libavcodec/bswap.h.orig	Sun Dec  5 16:03:35 2004
+++ libavcodec/bswap.h	Sun Dec  5 16:06:48 2004
@@ -10,6 +10,14 @@
 #include <byteswap.h>
 #else
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#include <sys/endian.h>
+#endif
+
 #ifdef ARCH_X86
 static inline unsigned short ByteSwap16(unsigned short x)
 {
@@ -18,7 +26,11 @@
         "0" (x));
     return x;
 }
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#define bswap_16(x) (be16toh(x))
+#else
 #define bswap_16(x) ByteSwap16(x)
+#endif
 
 static inline unsigned int ByteSwap32(unsigned int x)
 {
@@ -34,7 +46,11 @@
       "0" (x));
   return x;
 }
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#define bswap_32(x) (be32toh(x))
+#else
 #define bswap_32(x) ByteSwap32(x)
+#endif
 
 static inline unsigned long long int ByteSwap64(unsigned long long int x)
 {
@@ -45,7 +61,11 @@
       "0"(bswap_32((unsigned long)x)),"1"(bswap_32((unsigned long)(x>>32))));
   return __x.__ll;
 }
+#if defined(__FreeBSD__) && __FreeBSD_version >= 510000
+#define bswap_64(x) (be64toh(x))
+#else
 #define bswap_64(x) ByteSwap64(x)
+#endif
 
 #elif defined(ARCH_SH4)
 

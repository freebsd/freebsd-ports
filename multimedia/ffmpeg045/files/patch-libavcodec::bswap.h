--- libavcodec/bswap.h.orig	Sun Nov  3 04:51:51 2002
+++ libavcodec/bswap.h	Sun Nov  3 04:53:30 2002
@@ -5,6 +5,14 @@
 #include <byteswap.h>
 #else
 
+#if (defined(BSD) && (BSD >= 199103))
+#include <sys/param.h>
+#endif
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#include <sys/endian.h>
+#endif
+
 #ifdef ARCH_X86
 inline static unsigned short ByteSwap16(unsigned short x)
 {
@@ -13,7 +21,11 @@
         "0" (x));
     return x;
 }
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#define bswap_16(x) (be16toh(x))
+#else
 #define bswap_16(x) ByteSwap16(x)
+#endif
 
 inline static unsigned int ByteSwap32(unsigned int x)
 {
@@ -29,7 +41,11 @@
       "0" (x));
   return x;
 }
+#if defined(__FreeBSD__) && __FreeBSD_version >= 470000
+#define bswap_32(x) (be32toh(x))
+#else
 #define bswap_32(x) ByteSwap32(x)
+#endif
 
 inline static unsigned long long int ByteSwap64(unsigned long long int x)
 {

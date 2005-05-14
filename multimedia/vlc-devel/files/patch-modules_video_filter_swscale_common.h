--- modules/video_filter/swscale/common.h.orig	Fri May 13 03:23:24 2005
+++ modules/video_filter/swscale/common.h	Fri May 13 03:37:24 2005
@@ -36,7 +36,17 @@
 #define MANGLE(a) #a
 #endif
 
-#ifdef ARCH_X86
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if (defined(__FreeBSD__) && __FreeBSD_version >= 500000)
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#elif (defined(__FreeBSD__) && __FreeBSD_version <= 500000)
+#include <sys/endian.h>
+#define bswap_16(x) be16toh(x)
+#elif ARCH_X86
 static inline unsigned short ByteSwap16(unsigned short x)
 {
   __asm("xchgb %b0,%h0" :

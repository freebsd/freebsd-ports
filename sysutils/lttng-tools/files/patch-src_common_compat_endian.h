--- src/common/compat/endian.h.orig	2016-11-29 22:48:37 UTC
+++ src/common/compat/endian.h
@@ -27,7 +27,19 @@
  */
 #ifdef __USE_BSD
 /* Conversion interfaces. */
-# include <byteswap.h>
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#define bswap_64 bswap64
+#define __bswap_16 bswap16
+#define __bswap_32 bswap32
+#define __bswap_64 bswap64
+#define NT_GNU_BUILD_ID 3
+#else
+#include <byteswap.h>
+#endif
 
 # if __BYTE_ORDER == __LITTLE_ENDIAN
 #  ifndef htobe16

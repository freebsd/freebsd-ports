--- crypto/encryptor.cc.orig	2011-09-09 01:49:35.000000000 +0300
+++ crypto/encryptor.cc	2011-09-09 01:56:01.000000000 +0300
@@ -18,6 +18,11 @@
 #define bswap_16(x) OSSwapInt16(x)
 #define bswap_32(x) OSSwapInt32(x)
 #define bswap_64(x) OSSwapInt64(x)
+#elif defined(OS_FREEBSD)
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #else
 #include <byteswap.h>
 #endif

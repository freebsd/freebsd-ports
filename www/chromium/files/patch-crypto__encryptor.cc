--- crypto/encryptor.cc.orig	2012-01-18 11:11:42.000000000 +0200
+++ crypto/encryptor.cc	2012-01-29 17:11:33.000000000 +0200
@@ -13,6 +13,11 @@
 #define bswap_16(x) _byteswap_ushort(x)
 #define bswap_32(x) _byteswap_ulong(x)
 #define bswap_64(x) _byteswap_uint64(x)
+#elif defined(OS_FREEBSD)
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #elif defined(OS_MACOSX)
 #include <libkern/OSByteOrder.h>
 #define bswap_16(x) OSSwapInt16(x)

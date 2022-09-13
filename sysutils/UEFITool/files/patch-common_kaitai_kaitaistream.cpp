--- ../common/kaitai/kaitaistream.cpp.orig	2022-09-11 22:19:28 UTC
+++ ../common/kaitai/kaitaistream.cpp
@@ -20,8 +20,10 @@
 #define bswap_32(x) _byteswap_ulong(x)
 #define bswap_64(x) _byteswap_uint64(x)
 #else // !__APPLE__ or !_MSC_VER
-#include <endian.h>
-#include <byteswap.h>
+#include <sys/endian.h>
+#define bswap_16(x) bswap16(x)
+#define bswap_32(x) bswap32(x)
+#define bswap_64(x) bswap64(x)
 #endif
 
 #include <iostream>

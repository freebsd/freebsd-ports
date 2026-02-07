--- src/3rdparty/chromium/third_party/smhasher/src/City.cpp.orig	2019-10-27 22:10:58.672918000 +0100
+++ src/3rdparty/chromium/third_party/smhasher/src/City.cpp	2019-10-27 22:12:39.653255000 +0100
@@ -65,11 +65,11 @@
 #define bswap_64(x) OSSwapInt64(x)
 
 #else
-#include <byteswap.h>
+#include <sys/endian.h>
 #endif
 
-#define uint32_in_expected_order(x) (bswap_32(x))
-#define uint64_in_expected_order(x) (bswap_64(x))
+#define uint32_in_expected_order(x) (bswap32(x))
+#define uint64_in_expected_order(x) (bswap64(x))
 
 #endif  // __BIG_ENDIAN__
 

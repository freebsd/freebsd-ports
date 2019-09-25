--- src/cpp-ethereum/ethash/lib/ethash/keccak.c.orig	2018-12-14 16:19:59 UTC
+++ src/cpp-ethereum/ethash/lib/ethash/keccak.c
@@ -13,7 +13,7 @@
 #define __LITTLE_ENDIAN 1234
 #define __BIG_ENDIAN 4321
 #define __BYTE_ORDER __LITTLE_ENDIAN
-#elif __APPLE__
+#elif __APPLE__ || __FreeBSD__
 #include <machine/endian.h>
 #else
 #include <endian.h>

--- lib/ethash/endianness.hpp.orig	2023-04-03 20:30:42 UTC
+++ lib/ethash/endianness.hpp
@@ -24,13 +24,15 @@
 #endif
 #endif
 
-#if __has_builtin(__builtin_bswap64) || defined(__GNUC__)
+#if (__has_builtin(__builtin_bswap64) || defined(__GNUC__)) && !defined(__FreeBSD__)
 #define bswap32 __builtin_bswap32
 #define bswap64 __builtin_bswap64
 #elif defined(_MSC_VER)
 #include <stdlib.h>
 #define bswap32 _byteswap_ulong
 #define bswap64 _byteswap_uint64
+#elif defined(__FreeBSD__)
+#include <sys/endian.h>
 #endif
 
 namespace ethash

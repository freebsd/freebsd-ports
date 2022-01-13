--- lib/ethash/endianness.hpp.orig	2021-11-09 08:29:42 UTC
+++ lib/ethash/endianness.hpp
@@ -24,7 +24,7 @@
 #endif
 #endif
 
-#if __has_builtin(__builtin_bswap64) || defined(__GNUC__)
+#if (__has_builtin(__builtin_bswap64) || defined(__GNUC__)) && !defined(__FreeBSD__)
 #define bswap32 __builtin_bswap32
 #define bswap64 __builtin_bswap64
 #elif defined(_MSC_VER)

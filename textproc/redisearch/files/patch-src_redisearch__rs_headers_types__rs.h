--- src/redisearch_rs/headers/types_rs.h.orig	2026-05-30 14:27:46 UTC
+++ src/redisearch_rs/headers/types_rs.h
@@ -17,7 +17,7 @@
 typedef uint16_t t_fieldIndex;
 
 /* Copied from `redisearch.h` */
-#if (defined(__x86_64__) || defined(__aarch64__) || defined(__arm64__)) && !defined(RS_NO_U128)
+#if (defined(__x86_64__) || defined(__aarch64__) || defined(__arm64__) || defined(__powerpc64__)) && !defined(RS_NO_U128)
 /* 64 bit architectures use 128 bit field masks and up to 128 fields */
 typedef __uint128_t t_fieldMask;
 #else

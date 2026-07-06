--- src/redisearch.h.orig	2026-05-30 14:27:46 UTC
+++ src/redisearch.h
@@ -39,7 +39,7 @@
 
 #define DOCID_MAX UINT64_MAX
 
-#if (defined(__x86_64__) || defined(__aarch64__) || defined(__arm64__)) && !defined(RS_NO_U128)
+#if (defined(__x86_64__) || defined(__aarch64__) || defined(__arm64__) || defined(__powerpc64__)) && !defined(RS_NO_U128)
 /* 64 bit architectures use 128 bit field masks and up to 128 fields */
 typedef __uint128_t t_fieldMask;
 #define RS_FIELDMASK_ALL (((__uint128_t)1 << 127) - (__uint128_t)1 + ((__uint128_t)1 << 127))

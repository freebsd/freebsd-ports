--- v8/src/objects/simd.cc.orig	2026-09-25 15:26:43 UTC
+++ v8/src/objects/simd.cc
@@ -350,7 +350,7 @@ uintptr_t fast_search_avx(T* array, uintptr_t array_le
 
 // When built with other toolchains, do not count on it to expose
 // __builtin_sve_* on a per-function basis. Fallback to Neon.
-#if defined(NEON64) && defined(__clang__)
+#if defined(NEON64) && defined(__clang__) && !defined(__OpenBSD__)
 #define V8_ENABLE_SIMD_SVE 1
 
 template <typename ScalarType>

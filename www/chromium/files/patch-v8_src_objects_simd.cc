--- v8/src/objects/simd.cc.orig	2026-10-18 13:29:39 UTC
+++ v8/src/objects/simd.cc
@@ -353,7 +353,7 @@ uintptr_t fast_search_avx(T* array, uintptr_t array_le
 // mangling SVE types with the Microsoft C++ ABI since version 21.
 // Fallback to Neon in cases where SVE is not supported.
 #if defined(NEON64) && defined(__clang__) && \
-    (!defined(V8_TARGET_OS_WIN) || __clang_major__ >= 21)
+    (!defined(V8_TARGET_OS_WIN) || __clang_major__ >= 21) && !defined(__OpenBSD__)
 #define V8_ENABLE_SIMD_SVE 1
 
 template <typename ScalarType>

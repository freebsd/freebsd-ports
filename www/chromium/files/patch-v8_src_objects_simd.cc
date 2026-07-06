--- v8/src/objects/simd.cc.orig	2026-07-02 06:01:51 UTC
+++ v8/src/objects/simd.cc
@@ -347,7 +347,7 @@ uintptr_t fast_search_avx(T* array, uintptr_t array_le
 }
 #endif  // ifdef __SSE3__
 
-#ifdef NEON64
+#if defined(NEON64) && !defined(V8_TARGET_OS_OPENBSD)
 
 template <typename ScalarType>
 struct SVEOperations {
@@ -637,9 +637,11 @@ template <typename T>
 inline uintptr_t search(T* array, uintptr_t array_len, uintptr_t index,
                         T search_element) {
 #ifdef NEON64
+#ifndef V8_TARGET_OS_OPENBSD
   if (get_vectorization_kind() == SimdKinds::kSVE) {
     return fast_search_sve(array, array_len, index, search_element);
   }
+#endif
 #else
   if (get_vectorization_kind() == SimdKinds::kAVX2) {
     return fast_search_avx(array, array_len, index, search_element);

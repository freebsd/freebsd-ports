--- v8/src/objects/simd.cc.orig	2022-08-06 09:56:20 UTC
+++ v8/src/objects/simd.cc
@@ -151,10 +151,15 @@ inline int extract_first_nonzero_index(float64x2_t v) 
 template <typename T>
 inline uintptr_t fast_search_noavx(T* array, uintptr_t array_len,
                                    uintptr_t index, T search_element) {
-  static_assert(std::is_same<T, uint32_t>::value ||
-                std::is_same<T, uint64_t>::value ||
-                std::is_same<T, double>::value);
+  static constexpr bool is_uint32 =
+      sizeof(T) == sizeof(uint32_t) && std::is_integral<T>::value;
+  static constexpr bool is_uint64 =
+      sizeof(T) == sizeof(uint64_t) && std::is_integral<T>::value;
+  static constexpr bool is_double =
+      sizeof(T) == sizeof(double) && std::is_floating_point<T>::value;
 
+  static_assert(is_uint32 || is_uint64 || is_double);
+
 #if !(defined(__SSE3__) || defined(NEON64))
   // No SIMD available.
   return slow_search(array, array_len, index, search_element);
@@ -181,14 +186,14 @@ inline uintptr_t fast_search_noavx(T* array, uintptr_t
 
   // Inserting one of the vectorized loop
 #ifdef __SSE3__
-  if constexpr (std::is_same<T, uint32_t>::value) {
+  if constexpr (is_uint32) {
 #define MOVEMASK(x) _mm_movemask_ps(_mm_castsi128_ps(x))
 #define EXTRACT(x) base::bits::CountTrailingZeros32(x)
     VECTORIZED_LOOP_x86(__m128i, __m128i, _mm_set1_epi32, _mm_cmpeq_epi32,
                         MOVEMASK, EXTRACT)
 #undef MOVEMASK
 #undef EXTRACT
-  } else if constexpr (std::is_same<T, uint64_t>::value) {
+  } else if constexpr (is_double) {
 #define SET1(x) _mm_castsi128_ps(_mm_set1_epi64x(x))
 #define CMP(a, b) _mm_cmpeq_pd(_mm_castps_pd(a), _mm_castps_pd(b))
 #define EXTRACT(x) base::bits::CountTrailingZeros32(x)
@@ -203,13 +208,13 @@ inline uintptr_t fast_search_noavx(T* array, uintptr_t
 #undef EXTRACT
   }
 #elif defined(NEON64)
-  if constexpr (std::is_same<T, uint32_t>::value) {
+  if constexpr (is_uint32) {
     VECTORIZED_LOOP_Neon(int32x4_t, int32x4_t, vdupq_n_u32, vceqq_u32,
                          vmaxvq_u32)
-  } else if constexpr (std::is_same<T, uint64_t>::value) {
+  } else if constexpr (is_uint64) {
     VECTORIZED_LOOP_Neon(int64x2_t, int64x2_t, vdupq_n_u64, vceqq_u64,
                          vmaxvq_u32)
-  } else if constexpr (std::is_same<T, double>::value) {
+  } else if constexpr (is_double) {
     VECTORIZED_LOOP_Neon(float64x2_t, float64x2_t, vdupq_n_f64, vceqq_f64,
                          vmaxvq_f64)
   }
@@ -243,10 +248,15 @@ template <typename T>
 TARGET_AVX2 inline uintptr_t fast_search_avx(T* array, uintptr_t array_len,
                                              uintptr_t index,
                                              T search_element) {
-  static_assert(std::is_same<T, uint32_t>::value ||
-                std::is_same<T, uint64_t>::value ||
-                std::is_same<T, double>::value);
+  static constexpr bool is_uint32 =
+      sizeof(T) == sizeof(uint32_t) && std::is_integral<T>::value;
+  static constexpr bool is_uint64 =
+      sizeof(T) == sizeof(uint64_t) && std::is_integral<T>::value;
+  static constexpr bool is_double =
+      sizeof(T) == sizeof(double) && std::is_floating_point<T>::value;
 
+  static_assert(is_uint32 || is_uint64 || is_double);
+
   const int target_align = 32;
   // Scalar loop to reach desired alignment
   for (;
@@ -259,21 +269,21 @@ TARGET_AVX2 inline uintptr_t fast_search_avx(T* array,
   }
 
   // Generating vectorized loop
-  if constexpr (std::is_same<T, uint32_t>::value) {
+  if constexpr (is_uint32) {
 #define MOVEMASK(x) _mm256_movemask_ps(_mm256_castsi256_ps(x))
 #define EXTRACT(x) base::bits::CountTrailingZeros32(x)
     VECTORIZED_LOOP_x86(__m256i, __m256i, _mm256_set1_epi32, _mm256_cmpeq_epi32,
                         MOVEMASK, EXTRACT)
 #undef MOVEMASK
 #undef EXTRACT
-  } else if constexpr (std::is_same<T, uint64_t>::value) {
+  } else if constexpr (is_uint64) {
 #define MOVEMASK(x) _mm256_movemask_pd(_mm256_castsi256_pd(x))
 #define EXTRACT(x) base::bits::CountTrailingZeros32(x)
     VECTORIZED_LOOP_x86(__m256i, __m256i, _mm256_set1_epi64x,
                         _mm256_cmpeq_epi64, MOVEMASK, EXTRACT)
 #undef MOVEMASK
 #undef EXTRACT
-  } else if constexpr (std::is_same<T, double>::value) {
+  } else if constexpr (is_double) {
 #define CMP(a, b) _mm256_cmp_pd(a, b, _CMP_EQ_OQ)
 #define EXTRACT(x) base::bits::CountTrailingZeros32(x)
     VECTORIZED_LOOP_x86(__m256d, __m256d, _mm256_set1_pd, CMP,

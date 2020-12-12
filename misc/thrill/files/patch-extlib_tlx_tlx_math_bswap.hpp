--- extlib/tlx/tlx/math/bswap.hpp.orig	2020-12-12 21:48:10 UTC
+++ extlib/tlx/tlx/math/bswap.hpp
@@ -35,9 +35,11 @@ static inline uint16_t bswap16_generic(const uint16_t&
 #if defined(__GNUC__) || defined(__clang__)
 
 //! bswap16 - gcc/clang intrinsic
+#if !defined(__FreeBSD__)
 static inline uint16_t bswap16(const uint16_t& v) {
     return __builtin_bswap16(v);
 }
+#endif
 
 #elif defined(_MSC_VER)
 
@@ -67,9 +69,11 @@ static inline uint32_t bswap32_generic(const uint32_t&
 #if defined(__GNUC__) || defined(__clang__)
 
 //! bswap32 - gcc/clang intrinsic
+#if !defined(__FreeBSD__)
 static inline uint32_t bswap32(const uint32_t& v) {
     return __builtin_bswap32(v);
 }
+#endif
 
 #elif defined(_MSC_VER)
 
@@ -105,9 +109,11 @@ static inline uint64_t bswap64_generic(const uint64_t&
 #if defined(__GNUC__) || defined(__clang__)
 
 //! bswap64 - gcc/clang intrinsic
+#if !defined(__FreeBSD__)
 static inline uint64_t bswap64(const uint64_t& v) {
     return __builtin_bswap64(v);
 }
+#endif
 
 #elif defined(_MSC_VER)
 

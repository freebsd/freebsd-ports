--- extlib/tlx/tlx/math/bswap.hpp.orig	2019-10-28 13:53:21 UTC
+++ extlib/tlx/tlx/math/bswap.hpp
@@ -19,6 +19,10 @@
 #include <cstdlib>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#endif
+
 namespace tlx {
 
 //! \addtogroup tlx_math
@@ -35,9 +39,11 @@ static inline uint16_t bswap16_generic(const uint16_t&
 #if defined(__GNUC__) || defined(__clang__)
 
 //! bswap16 - gcc/clang intrinsic
+#if !defined(__FreeBSD__)
 static inline uint16_t bswap16(const uint16_t& v) {
     return __builtin_bswap16(v);
 }
+#endif
 
 #elif defined(_MSC_VER)
 
@@ -67,9 +73,11 @@ static inline uint32_t bswap32_generic(const uint32_t&
 #if defined(__GNUC__) || defined(__clang__)
 
 //! bswap32 - gcc/clang intrinsic
+#if !defined(__FreeBSD__)
 static inline uint32_t bswap32(const uint32_t& v) {
     return __builtin_bswap32(v);
 }
+#endif
 
 #elif defined(_MSC_VER)
 
@@ -105,9 +113,11 @@ static inline uint64_t bswap64_generic(const uint64_t&
 #if defined(__GNUC__) || defined(__clang__)
 
 //! bswap64 - gcc/clang intrinsic
+#if !defined(__FreeBSD__)
 static inline uint64_t bswap64(const uint64_t& v) {
     return __builtin_bswap64(v);
 }
+#endif
 
 #elif defined(_MSC_VER)
 

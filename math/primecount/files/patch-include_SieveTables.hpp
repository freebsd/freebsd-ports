--- include/SieveTables.hpp.orig	2021-12-20 20:37:55 UTC
+++ include/SieveTables.hpp
@@ -60,22 +60,22 @@ constexpr int right_shift(int n)
 /// on big endian CPU architectures.
 
 /// Reverse byte order of 64-bit integer
-constexpr uint64_t bswap64(uint64_t i, uint64_t j = 0, uint64_t n = 0)
+constexpr uint64_t bswap_64(uint64_t i, uint64_t j = 0, uint64_t n = 0)
 {
   return (n == sizeof(uint64_t)) ? j :
-    bswap64(i >> 8, (j << 8) | (i & 0xff), n + 1);
+    bswap_64(i >> 8, (j << 8) | (i & 0xff), n + 1);
 }
 
 /// Bitmask to unset bits <= n
 constexpr uint64_t unset_s(int n)
 {
-  return bswap64(~0ull << left_shift(n));
+  return bswap_64(~0ull << left_shift(n));
 }
 
 /// Bitmask to unset bits >= n
 constexpr uint64_t unset_l(int n)
 {
-  return bswap64((n == 0) ? 0 : ~0ull >> right_shift(n));
+  return bswap_64((n == 0) ? 0 : ~0ull >> right_shift(n));
 }
 
 #else

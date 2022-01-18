--- packages/arb-avm-cpp/data_storage/include/data_storage/value/valuecache.hpp.orig	2021-12-14 20:02:23 UTC
+++ packages/arb-avm-cpp/data_storage/include/data_storage/value/valuecache.hpp
@@ -30,7 +30,7 @@ class ValueCache {
    private:
     struct ValueCacheHasher {
         std::size_t operator()(const uint256_t& hash) const noexcept {
-            return intx::narrow_cast<std::size_t>(hash);
+            return narrow_cast<std::size_t>(hash);
         }
     };
 

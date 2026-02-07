--- third_party/test_fonts/fontconfig/generate_fontconfig_caches.cc.orig	2025-11-01 06:40:37 UTC
+++ third_party/test_fonts/fontconfig/generate_fontconfig_caches.cc
@@ -56,7 +56,7 @@ int main() {
   FcFini();
 
   // Check existence of intended fontconfig cache file.
-  auto cache = fontconfig_caches + "/" + kCacheKey + "-le64.cache-11";
+  auto cache = fontconfig_caches + "/" + kCacheKey + "-le64.cache-" + FC_CACHE_VERSION;
   bool cache_exists = access(cache.c_str(), F_OK) == 0;
   return !cache_exists;
 }

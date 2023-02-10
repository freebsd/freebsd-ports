--- third_party/test_fonts/fontconfig/generate_fontconfig_caches.cc.orig	2023-01-14 16:09:37 UTC
+++ third_party/test_fonts/fontconfig/generate_fontconfig_caches.cc
@@ -56,7 +56,7 @@ int main() {
   FcFini();
 
   // Check existence of intended fontconfig cache file.
-  auto cache = fontconfig_caches + "/" + kCacheKey + "-le64.cache-7";
+  auto cache = fontconfig_caches + "/" + kCacheKey + "-le64.cache-" + FC_CACHE_VERSION;
   bool cache_exists = access(cache.c_str(), F_OK) == 0;
   return !cache_exists;
 }

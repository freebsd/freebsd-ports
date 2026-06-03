--- src/3rdparty/chromium/content/browser/code_cache/generated_code_cache.h.orig	2025-04-23 16:00:55 UTC
+++ src/3rdparty/chromium/content/browser/code_cache/generated_code_cache.h
@@ -53,7 +53,8 @@ class CONTENT_EXPORT GeneratedCodeCache {
   enum CodeCacheType { kJavaScript, kWebAssembly };
 
   // Used for collecting statistics about cache behaviour.
-  enum CacheEntryStatus {
+  // Since it's uploaded to UMA, its values must never change.
+  enum CacheEntryStatus : uint8_t {
     kHit,
     kMiss,
     kClear,

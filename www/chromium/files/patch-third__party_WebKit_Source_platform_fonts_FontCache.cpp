--- third_party/WebKit/Source/platform/fonts/FontCache.cpp.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/fonts/FontCache.cpp
@@ -63,9 +63,9 @@ using namespace WTF;
 
 namespace blink {
 
-#if !OS(WIN) && !OS(LINUX)
+#if !OS(WIN) && !OS(LINUX) && !OS(FREEBSD)
 FontCache::FontCache() : purge_prevent_count_(0), font_manager_(nullptr) {}
-#endif  // !OS(WIN) && !OS(LINUX)
+#endif  // !OS(WIN) && !OS(LINUX) && !OS(FREEBSD)
 
 typedef HashMap<unsigned,
                 std::unique_ptr<FontPlatformData>,

--- third_party/WebKit/Source/platform/fonts/FontCache.cpp.orig	2017-04-19 19:06:50 UTC
+++ third_party/WebKit/Source/platform/fonts/FontCache.cpp
@@ -63,9 +63,9 @@ using namespace WTF;
 
 namespace blink {
 
-#if !OS(WIN) && !OS(LINUX)
+#if !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD)
 FontCache::FontCache() : m_purgePreventCount(0), m_fontManager(nullptr) {}
-#endif  // !OS(WIN) && !OS(LINUX)
+#endif  // !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD)
 
 typedef HashMap<unsigned,
                 std::unique_ptr<FontPlatformData>,

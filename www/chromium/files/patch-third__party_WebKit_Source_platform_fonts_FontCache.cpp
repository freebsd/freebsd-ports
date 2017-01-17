--- third_party/WebKit/Source/platform/fonts/FontCache.cpp.orig	2016-12-13 00:43:16 UTC
+++ third_party/WebKit/Source/platform/fonts/FontCache.cpp
@@ -61,9 +61,9 @@ using namespace WTF;
 
 namespace blink {
 
-#if !OS(WIN) && !OS(LINUX)
+#if !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD)
 FontCache::FontCache() : m_purgePreventCount(0), m_fontManager(nullptr) {}
-#endif  // !OS(WIN) && !OS(LINUX)
+#endif  // !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD)
 
 typedef HashMap<unsigned,
                 std::unique_ptr<FontPlatformData>,

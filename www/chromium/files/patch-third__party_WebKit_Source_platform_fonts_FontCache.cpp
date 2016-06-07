--- third_party/WebKit/Source/platform/fonts/FontCache.cpp.orig	2016-05-27 10:30:48.384014000 -0400
+++ third_party/WebKit/Source/platform/fonts/FontCache.cpp	2016-05-27 10:31:19.845787000 -0400
@@ -59,13 +59,13 @@
 
 namespace blink {
 
-#if !OS(WIN) && !OS(LINUX)
+#if !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD)
 FontCache::FontCache()
     : m_purgePreventCount(0)
     , m_fontManager(nullptr)
 {
 }
-#endif // !OS(WIN) && !OS(LINUX)
+#endif // !OS(WIN) && !OS(LINUX) && !OS(FREEBSD) && !OS(OPENBSD)
 
 typedef HashMap<FontCacheKey, OwnPtr<FontPlatformData>, FontCacheKeyHash, FontCacheKeyTraits> FontPlatformDataCache;
 typedef HashMap<FallbackListCompositeKey, OwnPtr<ShapeCache>, FallbackListCompositeKeyHash, FallbackListCompositeKeyTraits> FallbackListShaperCache;

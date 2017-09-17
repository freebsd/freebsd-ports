--- third_party/WebKit/Source/platform/fonts/FontCache.cpp.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/fonts/FontCache.cpp	2017-09-06 21:33:11.655017000 +0200
@@ -64,9 +64,9 @@
 
 namespace blink {
 
-#if !defined(OS_WIN) && !defined(OS_LINUX)
+#if !defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)
 FontCache::FontCache() : purge_prevent_count_(0), font_manager_(nullptr) {}
-#endif  // !defined(OS_WIN) && !defined(OS_LINUX)
+#endif  // !defined(OS_WIN) && !defined(OS_LINUX) && !defined(OS_BSD)
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
@@ -85,7 +85,7 @@
 FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (family.IsEmpty() || family == FontFamilyNames::system_ui)
     return nullptr;
 #else

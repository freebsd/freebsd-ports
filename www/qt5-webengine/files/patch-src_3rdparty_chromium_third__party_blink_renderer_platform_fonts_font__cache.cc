--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -65,7 +65,7 @@ namespace blink {
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -88,7 +88,7 @@ FontCache::FontCache()
 FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (family.IsEmpty() || family == FontFamilyNames::system_ui)
     return nullptr;
 #else

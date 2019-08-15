--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2019-07-24 18:58:42 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -72,7 +72,7 @@ static const char kColorEmojiLocale[] = "und-Zsye";
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -95,7 +95,7 @@ FontCache::FontCache()
 FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (family.IsEmpty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else

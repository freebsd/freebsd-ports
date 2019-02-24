--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2019-01-30 02:18:16.000000000 +0100
+++ third_party/blink/renderer/platform/fonts/font_cache.cc	2019-02-01 14:43:30.711803000 +0100
@@ -65,7 +65,7 @@
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -88,7 +88,7 @@
 FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (family.IsEmpty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else

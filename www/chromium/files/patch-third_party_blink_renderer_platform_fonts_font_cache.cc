--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2018-12-12 22:56:23.000000000 +0100
+++ third_party/blink/renderer/platform/fonts/font_cache.cc	2018-12-29 13:18:26.479678000 +0100
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
   if (family.IsEmpty() || family == FontFamilyNames::system_ui)
     return nullptr;
 #else

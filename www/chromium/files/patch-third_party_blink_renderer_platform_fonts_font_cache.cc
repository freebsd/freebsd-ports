--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2018-07-19 19:24:25.598357000 +0200
+++ third_party/blink/renderer/platform/fonts/font_cache.cc	2018-07-19 19:24:38.659689000 +0200
@@ -85,7 +85,7 @@
 FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (family.IsEmpty() || family == FontFamilyNames::system_ui)
     return nullptr;
 #else

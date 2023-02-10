--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -75,7 +75,7 @@ SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
 SkFontMgr* FontCache::static_font_manager_ = nullptr;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -120,7 +120,7 @@ FontPlatformData* FontCache::SystemFontPlatformData(
 FontPlatformData* FontCache::SystemFontPlatformData(
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   if (family.IsEmpty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else

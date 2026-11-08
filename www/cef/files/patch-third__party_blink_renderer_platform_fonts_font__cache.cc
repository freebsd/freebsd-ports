--- third_party/blink/renderer/platform/fonts/font_cache.cc.orig	2026-08-12 09:02:10 UTC
+++ third_party/blink/renderer/platform/fonts/font_cache.cc
@@ -86,7 +86,7 @@ const char kMonoEmojiLocale[] = "und-Zsym";
 extern const char kNotoColorEmojiCompat[] = "Noto Color Emoji Compat";
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 float FontCache::device_scale_factor_ = 1.0;
 #endif
 
@@ -141,7 +141,7 @@ const FontPlatformData* FontCache::SystemFontPlatformD
     const FontDescription& font_description) {
   const AtomicString& family = FontCache::SystemFontFamily();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || \
-    BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
   if (family.empty() || family == font_family_names::kSystemUi)
     return nullptr;
 #else

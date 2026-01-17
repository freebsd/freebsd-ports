--- third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2026-01-16 13:40:34 UTC
+++ third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc
@@ -304,7 +304,7 @@ const FontPlatformData* FontCache::CreateFontPlatformD
   std::string name;
 
   sk_sp<SkTypeface> typeface;
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool noto_color_emoji_from_gmscore = false;
 #if BUILDFLAG(IS_ANDROID)
   // Use the unique local matching pathway for fetching Noto Color Emoji Compat

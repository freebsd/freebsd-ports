--- third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2026-10-18 13:29:39 UTC
+++ third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc
@@ -318,7 +318,7 @@ const FontPlatformData* FontCache::CreateFontPlatformD
   std::string name;
 
   sk_sp<SkTypeface> typeface;
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool noto_color_emoji_from_gmscore = false;
 #if BUILDFLAG(IS_ANDROID)
   // Use the unique local matching pathway for fetching Noto Color Emoji Compat

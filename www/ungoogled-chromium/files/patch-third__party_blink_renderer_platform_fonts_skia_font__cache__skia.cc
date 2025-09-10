--- third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2025-09-10 13:22:16 UTC
+++ third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc
@@ -65,7 +65,7 @@ AtomicString ToAtomicString(const SkString& str) {
   return AtomicString::FromUTF8(std::string_view(str.begin(), str.end()));
 }
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // This function is called on android or when we are emulating android fonts on
 // linux and the embedder has overriden the default fontManager with
 // WebFontRendering::setSkiaFontMgr.
@@ -260,7 +260,7 @@ const FontPlatformData* FontCache::CreateFontPlatformD
   std::string name;
 
   sk_sp<SkTypeface> typeface;
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool noto_color_emoji_from_gmscore = false;
 #if BUILDFLAG(IS_ANDROID)
   // Use the unique local matching pathway for fetching Noto Color Emoji Compat

--- third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2021-09-24 04:26:12 UTC
+++ third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc
@@ -60,7 +60,7 @@ AtomicString ToAtomicString(const SkString& str) {
   return AtomicString::FromUTF8(str.c_str(), str.size());
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // This function is called on android or when we are emulating android fonts on
 // linux and the embedder has overriden the default fontManager with
 // WebFontRendering::setSkiaFontMgr.
@@ -84,7 +84,7 @@ AtomicString FontCache::GetFamilyNameForCharacter(
   typeface->getFamilyName(&skia_family_name);
   return ToAtomicString(skia_family_name);
 }
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 void FontCache::PlatformInit() {}
 
@@ -239,7 +239,7 @@ sk_sp<SkTypeface> FontCache::CreateTypeface(
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_WIN) || defined(OS_BSD)
   // On linux if the fontManager has been overridden then we should be calling
   // the embedder provided font Manager rather than calling
   // SkTypeface::CreateFromName which may redirect the call to the default font
@@ -266,7 +266,7 @@ std::unique_ptr<FontPlatformData> FontCache::CreateFon
   std::string name;
 
   sk_sp<SkTypeface> typeface;
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool noto_color_emoji_from_gmscore = false;
 #if defined(OS_ANDROID)
   // Use the unique local matching pathway for fetching Noto Color Emoji Compat

--- third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2019-07-24 18:58:42 UTC
+++ third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc
@@ -60,7 +60,7 @@ AtomicString ToAtomicString(const SkString& str) {
   return AtomicString::FromUTF8(str.c_str(), str.size());
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 // This function is called on android or when we are emulating android fonts on
 // linux and the embedder has overriden the default fontManager with
 // WebFontRendering::setSkiaFontMgr.
@@ -83,7 +83,7 @@ AtomicString FontCache::GetFamilyNameForCharacter(
   typeface->getFamilyName(&skia_family_name);
   return ToAtomicString(skia_family_name);
 }
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 
 void FontCache::PlatformInit() {}
 
@@ -228,7 +228,7 @@ sk_sp<SkTypeface> FontCache::CreateTypeface(
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // On linux if the fontManager has been overridden then we should be calling
   // the embedder provided font Manager rather than calling
   // SkTypeface::CreateFromName which may redirect the call to the default font
@@ -255,7 +255,7 @@ std::unique_ptr<FontPlatformData> FontCache::CreateFon
   CString name;
 
   sk_sp<SkTypeface> typeface;
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   if (alternate_name == AlternateFontName::kLocalUniqueFace &&
       RuntimeEnabledFeatures::FontSrcLocalMatchingEnabled()) {
     typeface = CreateTypefaceFromUniqueName(creation_params, name);

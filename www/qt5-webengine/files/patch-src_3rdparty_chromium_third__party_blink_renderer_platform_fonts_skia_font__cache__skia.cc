--- src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc
@@ -59,7 +59,7 @@ AtomicString ToAtomicString(const SkString& str) {
   return AtomicString::FromUTF8(str.c_str(), str.size());
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -103,7 +103,7 @@ AtomicString FontCache::GetFamilyNameForCharacter(
   typeface->getFamilyName(&skia_family_name);
   return ToAtomicString(skia_family_name);
 }
-#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#endif  // defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 
 void FontCache::PlatformInit() {}
 
@@ -248,7 +248,7 @@ PaintTypeface FontCache::CreateTypeface(
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // On linux if the fontManager has been overridden then we should be calling
   // the embedder provided font Manager rather than calling
   // SkTypeface::CreateFromName which may redirect the call to the default font

--- third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2019-01-30 02:18:16.000000000 +0100
+++ third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc	2019-02-02 11:10:08.595129000 +0100
@@ -57,7 +57,7 @@
 
 namespace blink {
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 namespace {
 
 static sk_sp<SkTypeface> CreateTypefaceFromUniqueName(
@@ -80,7 +80,7 @@
   return AtomicString::FromUTF8(str.c_str(), str.size());
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -269,7 +269,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // On linux if the fontManager has been overridden then we should be calling
   // the embedder provided font Manager rather than calling
   // SkTypeface::CreateFromName which may redirect the call to the default font
@@ -296,7 +296,7 @@
   CString name;
 
   sk_sp<SkTypeface> typeface;
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
   if (alternate_name == AlternateFontName::kLocalUniqueFace &&
       RuntimeEnabledFeatures::FontSrcLocalMatchingEnabled()) {
     typeface = CreateTypefaceFromUniqueName(creation_params, name);

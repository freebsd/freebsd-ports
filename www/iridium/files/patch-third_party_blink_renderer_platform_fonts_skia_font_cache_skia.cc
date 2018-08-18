--- third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc.orig	2018-07-19 19:29:54.256436000 +0200
+++ third_party/blink/renderer/platform/fonts/skia/font_cache_skia.cc	2018-07-19 19:30:19.879244000 +0200
@@ -60,7 +60,7 @@
   return AtomicString::FromUTF8(str.c_str(), str.size());
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -249,7 +249,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // On linux if the fontManager has been overridden then we should be calling
   // the embedder provided font Manager rather than calling
   // SkTypeface::CreateFromName which may redirect the call to the default font

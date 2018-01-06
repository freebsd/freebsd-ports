--- src/3rdparty/chromium/third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp.orig	2017-01-26 00:49:28 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp
@@ -63,7 +63,7 @@ static sk_sp<SkTypeface> typefaceForFont
 
 namespace blink {
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(BSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -230,7 +230,7 @@ sk_sp<SkTypeface> FontCache::createTypef
   }
 #endif
 
-#if OS(LINUX) || OS(WIN)
+#if OS(LINUX) || OS(WIN) || OS(BSD)
   // On linux if the fontManager has been overridden then we should be calling
   // the embedder provided font Manager rather than calling
   // SkTypeface::CreateFromName which may redirect the call to the default font

--- third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp.orig	2017-02-02 02:03:10 UTC
+++ third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp
@@ -67,7 +67,7 @@ AtomicString toAtomicString(const SkStri
   return AtomicString::fromUTF8(str.c_str(), str.size());
 }
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(BSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -234,7 +234,7 @@ sk_sp<SkTypeface> FontCache::createTypef
   }
 #endif
 
-#if OS(LINUX) || OS(WIN)
+#if OS(LINUX) || OS(WIN) || OS(BSD)
   // On linux if the fontManager has been overridden then we should be calling
   // the embedder provided font Manager rather than calling
   // SkTypeface::CreateFromName which may redirect the call to the default font

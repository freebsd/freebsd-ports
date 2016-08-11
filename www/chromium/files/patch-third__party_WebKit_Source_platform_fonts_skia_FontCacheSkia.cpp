--- third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp.orig	2016-05-25 15:01:11.000000000 -0400
+++ third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp	2016-05-27 11:26:01.202711000 -0400
@@ -60,7 +60,7 @@
 
 namespace blink {
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -171,7 +171,7 @@
     return fontDataFromFontPlatformData(fontPlatformData, shouldRetain);
 }
 
-#if OS(WIN) || OS(LINUX)
+#if OS(WIN) || OS(LINUX) || OS(FREEBSD)
 static inline SkFontStyle fontStyle(const FontDescription& fontDescription)
 {
     int width = static_cast<int>(fontDescription.stretch());
@@ -232,7 +232,7 @@
     }
 #endif
 
-#if OS(LINUX)
+#if OS(LINUX) || OS(FREEBSD)
     // On linux if the fontManager has been overridden then we should be calling the embedder
     // provided font Manager rather than calling SkTypeface::CreateFromName which may redirect the
     // call to the default font Manager.

--- third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp.orig	2016-07-20 22:03:41.000000000 +0300
+++ third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp	2016-08-01 04:30:26.468814000 +0300
@@ -60,7 +60,7 @@
 
 namespace blink {
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(BSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -183,7 +183,7 @@
     }
 #endif
 
-#if OS(LINUX) || OS(WIN)
+#if OS(LINUX) || OS(WIN) || OS(BSD)
     // On linux if the fontManager has been overridden then we should be calling the embedder
     // provided font Manager rather than calling SkTypeface::CreateFromName which may redirect the
     // call to the default font Manager.

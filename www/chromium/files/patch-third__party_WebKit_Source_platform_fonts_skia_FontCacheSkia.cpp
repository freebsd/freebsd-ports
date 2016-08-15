--- third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp.orig	2016-07-22 00:07:09.000000000 -0400
+++ third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp	2016-08-03 15:39:36.482884000 -0400
@@ -60,7 +60,7 @@
 
 namespace blink {
 
-#if OS(ANDROID) || OS(LINUX)
+#if OS(ANDROID) || OS(LINUX) || OS(FREEBSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -183,7 +183,7 @@
     }
 #endif
 
-#if OS(LINUX) || OS(WIN)
+#if OS(LINUX) || OS(WIN) || OS(FREEBSD)
     // On linux if the fontManager has been overridden then we should be calling the embedder
     // provided font Manager rather than calling SkTypeface::CreateFromName which may redirect the
     // call to the default font Manager.

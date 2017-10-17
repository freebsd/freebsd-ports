--- third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/fonts/skia/FontCacheSkia.cpp	2017-09-06 21:56:16.263371000 +0200
@@ -73,7 +73,7 @@
   return AtomicString::FromUTF8(str.c_str(), str.size());
 }
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
 // Android special locale for retrieving the color emoji font
 // based on the proposed changes in UTR #51 for introducing
 // an Emoji script code:
@@ -258,7 +258,7 @@
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   // On linux if the fontManager has been overridden then we should be calling
   // the embedder provided font Manager rather than calling
   // SkTypeface::CreateFromName which may redirect the call to the default font

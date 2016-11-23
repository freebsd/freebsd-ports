--- third_party/WebKit/Source/platform/fonts/SimpleFontData.cpp.orig	2016-07-20 22:03:41.000000000 +0300
+++ third_party/WebKit/Source/platform/fonts/SimpleFontData.cpp	2016-08-12 10:20:18.427009000 +0300
@@ -49,7 +49,7 @@
 const float smallCapsFontSizeMultiplier = 0.7f;
 const float emphasisMarkFontSizeMultiplier = 0.5f;

-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
 // This is the largest VDMX table which we'll try to load and parse.
 static const size_t maxVDMXTableSize = 1024 * 1024; // 1 MB
 #endif
@@ -102,7 +102,7 @@
     int vdmxAscent = 0, vdmxDescent = 0;
     bool isVDMXValid = false;

-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
     // Manually digging up VDMX metrics is only applicable when bytecode hinting using FreeType.
     // With DirectWrite or CoreText, no bytecode hinting is ever done.
     // This code should be pushed into FreeType (hinted font metrics).
@@ -135,7 +135,7 @@
     } else {
         ascent = SkScalarRoundToInt(-metrics.fAscent);
         descent = SkScalarRoundToInt(metrics.fDescent);
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
         // When subpixel positioning is enabled, if the descent is rounded down, the descent part
         // of the glyph may be truncated when displayed in a 'overflow: hidden' container.
         // To avoid that, borrow 1 unit from the ascent when possible.

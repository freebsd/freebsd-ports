--- third_party/WebKit/Source/platform/fonts/SimpleFontData.cpp.orig	2016-12-13 00:50:37 UTC
+++ third_party/WebKit/Source/platform/fonts/SimpleFontData.cpp
@@ -51,7 +51,7 @@ namespace blink {
 const float smallCapsFontSizeMultiplier = 0.7f;
 const float emphasisMarkFontSizeMultiplier = 0.5f;
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
 // This is the largest VDMX table which we'll try to load and parse.
 static const size_t maxVDMXTableSize = 1024 * 1024;  // 1 MB
 #endif
@@ -105,7 +105,7 @@ void SimpleFontData::platformInit() {
   int vdmxAscent = 0, vdmxDescent = 0;
   bool isVDMXValid = false;
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
   // Manually digging up VDMX metrics is only applicable when bytecode hinting
   // using FreeType.  With DirectWrite or CoreText, no bytecode hinting is ever
   // done.  This code should be pushed into FreeType (hinted font metrics).
@@ -139,7 +139,7 @@ void SimpleFontData::platformInit() {
   } else {
     ascent = SkScalarRoundToInt(-metrics.fAscent);
     descent = SkScalarRoundToInt(metrics.fDescent);
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
     // When subpixel positioning is enabled, if the descent is rounded down, the
     // descent part of the glyph may be truncated when displayed in a 'overflow:
     // hidden' container.  To avoid that, borrow 1 unit from the ascent when

--- third_party/WebKit/Source/platform/fonts/SimpleFontData.cpp.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/fonts/SimpleFontData.cpp
@@ -50,7 +50,7 @@ namespace blink {
 const float kSmallCapsFontSizeMultiplier = 0.7f;
 const float kEmphasisMarkFontSizeMultiplier = 0.5f;
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
 // This is the largest VDMX table which we'll try to load and parse.
 static const size_t kMaxVDMXTableSize = 1024 * 1024;  // 1 MB
 #endif
@@ -105,7 +105,7 @@ void SimpleFontData::PlatformInit(bool subpixel_ascent
   int vdmx_ascent = 0, vdmx_descent = 0;
   bool is_vdmx_valid = false;
 
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
   // Manually digging up VDMX metrics is only applicable when bytecode hinting
   // using FreeType.  With DirectWrite or CoreText, no bytecode hinting is ever
   // done.  This code should be pushed into FreeType (hinted font metrics).
@@ -154,7 +154,7 @@ void SimpleFontData::PlatformInit(bool subpixel_ascent
       visual_overflow_inflation_for_ascent_ = 1;
     if (descent < metrics.fDescent) {
       visual_overflow_inflation_for_descent_ = 1;
-#if OS(LINUX) || OS(ANDROID)
+#if OS(LINUX) || OS(ANDROID) || OS(BSD)
       // When subpixel positioning is enabled, if the descent is rounded down,
       // the descent part of the glyph may be truncated when displayed in a
       // 'overflow: hidden' container.  To avoid that, borrow 1 unit from the

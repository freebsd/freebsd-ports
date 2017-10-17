--- third_party/WebKit/Source/platform/fonts/SimpleFontData.cpp.orig	2017-09-05 21:05:41.000000000 +0200
+++ third_party/WebKit/Source/platform/fonts/SimpleFontData.cpp	2017-09-06 21:49:52.325872000 +0200
@@ -56,7 +56,7 @@
 const float kSmallCapsFontSizeMultiplier = 0.7f;
 const float kEmphasisMarkFontSizeMultiplier = 0.5f;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
 // This is the largest VDMX table which we'll try to load and parse.
 static const size_t kMaxVDMXTableSize = 1024 * 1024;  // 1 MB
 #endif
@@ -111,7 +111,7 @@
   int vdmx_ascent = 0, vdmx_descent = 0;
   bool is_vdmx_valid = false;
 
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   // Manually digging up VDMX metrics is only applicable when bytecode hinting
   // using FreeType.  With DirectWrite or CoreText, no bytecode hinting is ever
   // done.  This code should be pushed into FreeType (hinted font metrics).
@@ -160,7 +160,7 @@
       visual_overflow_inflation_for_ascent_ = 1;
     if (descent < metrics.fDescent) {
       visual_overflow_inflation_for_descent_ = 1;
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
       // When subpixel positioning is enabled, if the descent is rounded down,
       // the descent part of the glyph may be truncated when displayed in a
       // 'overflow: hidden' container.  To avoid that, borrow 1 unit from the

--- third_party/pdfium/core/fxge/cfx_fontmapper.cpp.orig	2022-02-07 13:39:41 UTC
+++ third_party/pdfium/core/fxge/cfx_fontmapper.cpp
@@ -156,7 +156,7 @@ constexpr AltFontFamily kAltFontFamilies[] = {
     {"ForteMT", "Forte"},
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ASMJS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ASMJS) || defined(OS_BSD)
 const char kNarrowFamily[] = "LiberationSansNarrow";
 #elif defined(OS_ANDROID)
 const char kNarrowFamily[] = "RobotoCondensed";

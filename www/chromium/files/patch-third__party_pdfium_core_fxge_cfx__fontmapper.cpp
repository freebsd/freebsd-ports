--- third_party/pdfium/core/fxge/cfx_fontmapper.cpp.orig	2021-12-31 01:00:55 UTC
+++ third_party/pdfium/core/fxge/cfx_fontmapper.cpp
@@ -156,13 +156,13 @@ constexpr AltFontFamily kAltFontFamilies[] = {
     {"ForteMT", "Forte"},
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ASMJS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ASMJS) || defined(OS_BSD)
 const char kNarrowFamily[] = "LiberationSansNarrow";
 #elif defined(OS_ANDROID)
 const char kNarrowFamily[] = "RobotoCondensed";
 #else
 const char kNarrowFamily[] = "ArialNarrow";
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ASMJS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ASMJS) || defined(OS_BSD)
 
 ByteString TT_NormalizeName(ByteString norm) {
   norm.Remove(' ');

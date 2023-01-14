--- src/3rdparty/chromium/third_party/pdfium/core/fxge/cfx_fontmapper.cpp.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/third_party/pdfium/core/fxge/cfx_fontmapper.cpp
@@ -155,7 +155,7 @@ constexpr AltFontFamily kAltFontFamilies[] = {
     {"ForteMT", "Forte"},
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS) || BUILDFLAG(IS_BSD)
 const char kNarrowFamily[] = "LiberationSansNarrow";
 #elif BUILDFLAG(IS_ANDROID)
 const char kNarrowFamily[] = "RobotoCondensed";

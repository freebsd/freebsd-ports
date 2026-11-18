--- third_party/pdfium/core/fxge/cfx_fontmapper.cpp.orig	2026-11-17 21:17:00 UTC
+++ third_party/pdfium/core/fxge/cfx_fontmapper.cpp
@@ -42,7 +42,7 @@ constexpr AltFontFamily kAltFontFamilies[] = {
     {"ForteMT", "Forte"},
 };
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || defined(OS_ASMJS) || BUILDFLAG(IS_BSD)
 const char kNarrowFamily[] = "LiberationSansNarrow";
 #elif BUILDFLAG(IS_ANDROID)
 const char kNarrowFamily[] = "RobotoCondensed";

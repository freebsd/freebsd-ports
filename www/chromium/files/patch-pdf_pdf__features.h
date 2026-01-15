--- pdf/pdf_features.h.orig	2026-01-14 08:33:23 UTC
+++ pdf/pdf_features.h
@@ -31,7 +31,7 @@ BASE_DECLARE_FEATURE(kPdfUseShowSaveFilePicker);
 BASE_DECLARE_FEATURE(kPdfUseSkiaRenderer);
 BASE_DECLARE_FEATURE(kPdfXfaSupport);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kPdfiumPerRequestFontMatching);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 

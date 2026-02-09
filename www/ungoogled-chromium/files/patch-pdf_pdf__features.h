--- pdf/pdf_features.h.orig	2026-02-15 10:01:45 UTC
+++ pdf/pdf_features.h
@@ -32,7 +32,7 @@ BASE_DECLARE_FEATURE(kPdfUseSkiaRenderer);
 extern const base::FeatureParam<bool> kPdfUseSkiaPremultiplied;
 BASE_DECLARE_FEATURE(kPdfXfaSupport);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kPdfiumPerRequestFontMatching);
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 

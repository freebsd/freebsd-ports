--- printing/printing_features.h.orig	2026-01-16 14:21:21 UTC
+++ printing/printing_features.h
@@ -27,7 +27,7 @@ BASE_DECLARE_FEATURE(kApiPrintingMarginsAndScale);
 COMPONENT_EXPORT(PRINTING_BASE)
 BASE_DECLARE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 COMPONENT_EXPORT(PRINTING_BASE) BASE_DECLARE_FEATURE(kCupsIppPrintingBackend);
 #endif  // BUILDFLAG(IS_LINUX)
 

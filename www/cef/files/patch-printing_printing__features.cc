--- printing/printing_features.cc.orig	2026-07-01 06:24:19 UTC
+++ printing/printing_features.cc
@@ -17,7 +17,7 @@ namespace printing::features {
 BASE_FEATURE(kAlignPdfDefaultPrintSettingsWithHTML,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Use the CUPS IPP printing backend instead of the original CUPS backend that
 // calls the deprecated PPD API.
 BASE_FEATURE(kCupsIppPrintingBackend, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -40,7 +40,7 @@ BASE_FEATURE(kPrintWithReducedRasterization, base::FEA
 // Enables printing interactions with the operating system to be performed
 // out-of-process.
 BASE_FEATURE(kEnableOopPrintDrivers,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT

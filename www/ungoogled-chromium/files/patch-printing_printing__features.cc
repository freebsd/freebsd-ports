--- printing/printing_features.cc.orig	2025-09-10 13:22:16 UTC
+++ printing/printing_features.cc
@@ -26,7 +26,7 @@ BASE_FEATURE(kApiPrintingMarginsAndScale,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Use the CUPS IPP printing backend instead of the original CUPS backend that
 // calls the deprecated PPD API.
 BASE_FEATURE(kCupsIppPrintingBackend,
@@ -70,7 +70,7 @@ BASE_FEATURE(kUseXpsForPrintingFromPdf,
 // out-of-process.
 BASE_FEATURE(kEnableOopPrintDrivers,
              "EnableOopPrintDrivers",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT

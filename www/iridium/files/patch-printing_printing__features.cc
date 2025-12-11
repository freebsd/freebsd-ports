--- printing/printing_features.cc.orig	2025-12-10 15:04:57 UTC
+++ printing/printing_features.cc
@@ -22,7 +22,7 @@ BASE_FEATURE(kAddPrinterViaPrintscanmgr, base::FEATURE
 BASE_FEATURE(kApiPrintingMarginsAndScale, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Use the CUPS IPP printing backend instead of the original CUPS backend that
 // calls the deprecated PPD API.
 BASE_FEATURE(kCupsIppPrintingBackend, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -54,7 +54,7 @@ BASE_FEATURE(kUseXpsForPrintingFromPdf, base::FEATURE_
 // Enables printing interactions with the operating system to be performed
 // out-of-process.
 BASE_FEATURE(kEnableOopPrintDrivers,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT

--- printing/backend/print_backend_cups.cc.orig	2024-08-27 06:28:16 UTC
+++ printing/backend/print_backend_cups.cc
@@ -32,7 +32,7 @@
 #include "printing/mojom/print.mojom.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "base/feature_list.h"
 #include "printing/backend/cups_connection.h"
 #include "printing/backend/print_backend_cups_ipp.h"
@@ -283,7 +283,7 @@ bool PrintBackendCUPS::IsValidPrinter(const std::strin
 #if !BUILDFLAG(IS_CHROMEOS)
 scoped_refptr<PrintBackend> PrintBackend::CreateInstanceImpl(
     const std::string& locale) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kCupsIppPrintingBackend)) {
     return base::MakeRefCounted<PrintBackendCupsIpp>(CupsConnection::Create());
   }

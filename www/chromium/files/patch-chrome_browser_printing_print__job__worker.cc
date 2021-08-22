--- chrome/browser/printing/print_job_worker.cc.orig	2021-07-19 18:45:09 UTC
+++ chrome/browser/printing/print_job_worker.cc
@@ -47,7 +47,7 @@
 #include "printing/printing_features.h"
 #endif
 
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) && defined(USE_CUPS)
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)) && defined(USE_CUPS)
 #include "printing/mojom/print.mojom.h"
 #endif
 
@@ -228,7 +228,7 @@ void PrintJobWorker::UpdatePrintSettings(base::Value n
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         print_backend->GetPrinterDriverInfo(printer_name));
 
-#if defined(OS_LINUX) && defined(USE_CUPS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {
@@ -239,7 +239,7 @@ void PrintJobWorker::UpdatePrintSettings(base::Value n
       new_settings.SetKey(kSettingAdvancedSettings,
                           std::move(advanced_settings));
     }
-#endif  // defined(OS_LINUX) && defined(USE_CUPS)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS)
   }
 
   PrintingContext::Result result;

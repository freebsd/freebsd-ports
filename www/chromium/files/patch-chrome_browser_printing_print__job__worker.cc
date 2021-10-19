--- chrome/browser/printing/print_job_worker.cc.orig	2021-09-14 01:51:50 UTC
+++ chrome/browser/printing/print_job_worker.cc
@@ -224,7 +224,7 @@ void PrintJobWorker::UpdatePrintSettings(base::Value n
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         print_backend->GetPrinterDriverInfo(printer_name));
 
-#if defined(OS_LINUX) && defined(USE_CUPS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {
@@ -235,7 +235,7 @@ void PrintJobWorker::UpdatePrintSettings(base::Value n
       new_settings.SetKey(kSettingAdvancedSettings,
                           std::move(advanced_settings));
     }
-#endif  // defined(OS_LINUX) && defined(USE_CUPS)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS)
   }
 
   PrintingContext::Result result;

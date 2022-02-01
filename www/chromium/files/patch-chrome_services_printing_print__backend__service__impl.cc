--- chrome/services/printing/print_backend_service_impl.cc.orig	2021-12-16 14:57:02 UTC
+++ chrome/services/printing/print_backend_service_impl.cc
@@ -327,7 +327,7 @@ void PrintBackendServiceImpl::UpdatePrintSettings(
   crash_keys_ = std::make_unique<crash_keys::ScopedPrinterInfo>(
       print_backend_->GetPrinterDriverInfo(printer_name));
 
-#if defined(OS_LINUX) && defined(USE_CUPS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS)
   // Try to fill in advanced settings based upon basic info options.
   PrinterBasicInfo basic_info;
   if (print_backend_->GetPrinterBasicInfo(printer_name, &basic_info) ==
@@ -338,7 +338,7 @@ void PrintBackendServiceImpl::UpdatePrintSettings(
 
     job_settings[kSettingAdvancedSettings] = std::move(advanced_settings);
   }
-#endif  // defined(OS_LINUX) && defined(USE_CUPS)
+#endif  // (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_CUPS)
 
   // Use a one-time `PrintingContext` to do the update to print settings.
   // Intentionally do not cache this context here since the process model does

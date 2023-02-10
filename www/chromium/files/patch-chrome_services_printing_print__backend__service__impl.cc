--- chrome/services/printing/print_backend_service_impl.cc.orig	2023-02-08 09:03:45 UTC
+++ chrome/services/printing/print_backend_service_impl.cc
@@ -42,7 +42,7 @@
 #include "printing/backend/cups_connection_pool.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/no_destructor.h"
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_delegate_stub.h"
@@ -69,7 +69,7 @@ namespace printing {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void InstantiateLinuxUiDelegate() {
   // TODO(crbug.com/809738)  Until a real UI can be used in a utility process,
   // need to use the stub version.
@@ -485,7 +485,7 @@ void PrintBackendServiceImpl::Init(
   // `InitCommon()`.
   InitializeProcessForPrinting();
   print_backend_ = PrintBackend::CreateInstance(locale);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Test framework already initializes the UI, so this should not go in
   // `InitCommon()`.  Additionally, low-level Linux UI is not needed when tests
   // are using `TestPrintingContext`.
@@ -672,7 +672,7 @@ void PrintBackendServiceImpl::UpdatePrintSettings(
   crash_keys_ = std::make_unique<crash_keys::ScopedPrinterInfo>(
       print_backend_->GetPrinterDriverInfo(*printer_name));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_CUPS)
   // Try to fill in advanced settings based upon basic info options.
   PrinterBasicInfo basic_info;
   if (print_backend_->GetPrinterBasicInfo(*printer_name, &basic_info) ==

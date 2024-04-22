--- chrome/services/printing/print_backend_service_impl.cc.orig	2024-03-22 08:19:40 UTC
+++ chrome/services/printing/print_backend_service_impl.cc
@@ -49,7 +49,7 @@
 #include "printing/backend/cups_connection_pool.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/no_destructor.h"
 #include "ui/linux/linux_ui.h"
 #include "ui/linux/linux_ui_delegate_stub.h"
@@ -76,7 +76,7 @@ namespace printing {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void InstantiateLinuxUiDelegate() {
   // TODO(crbug.com/809738)  Until a real UI can be used in a utility process,
   // need to use the stub version.
@@ -85,7 +85,7 @@ void InstantiateLinuxUiDelegate() {
 #endif
 
 scoped_refptr<base::SequencedTaskRunner> GetPrintingTaskRunner() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Use task runner associated with equivalent of UI thread.  Needed for calls
   // made through `PrintDialogLinuxInterface` to properly execute.
   CHECK(base::SequencedTaskRunner::HasCurrentDefault());
@@ -469,7 +469,7 @@ void PrintBackendServiceImpl::Init(
   // `InitCommon()`.
   InitializeProcessForPrinting();
   print_backend_ = PrintBackend::CreateInstance(locale);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Test framework already initializes the UI, so this should not go in
   // `InitCommon()`.  Additionally, low-level Linux UI is not needed when tests
   // are using `TestPrintingContext`.
@@ -690,7 +690,7 @@ void PrintBackendServiceImpl::UpdatePrintSettings(
   crash_keys_ = std::make_unique<crash_keys::ScopedPrinterInfo>(
       *printer_name, print_backend_->GetPrinterDriverInfo(*printer_name));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(USE_CUPS)
   // Try to fill in advanced settings based upon basic info options.
   PrinterBasicInfo basic_info;
   if (print_backend_->GetPrinterBasicInfo(*printer_name, &basic_info) ==

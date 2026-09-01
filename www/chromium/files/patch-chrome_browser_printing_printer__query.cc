--- chrome/browser/printing/printer_query.cc.orig	2026-08-31 10:59:09 UTC
+++ chrome/browser/printing/printer_query.cc
@@ -346,7 +346,7 @@ void PrinterQuery::UpdatePrintSettings(base::DictValue
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         printer_name, print_backend->GetPrinterDriverInfo(printer_name));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS)
+#if (BUILDFLAG(IS_BSD) || BUILDFLAG(IS_LINUX)) && BUILDFLAG(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {

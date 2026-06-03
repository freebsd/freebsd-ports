--- chrome/browser/printing/printer_query.cc.orig	2026-03-13 06:02:14 UTC
+++ chrome/browser/printing/printer_query.cc
@@ -342,7 +342,7 @@ void PrinterQuery::UpdatePrintSettings(base::DictValue
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         printer_name, print_backend->GetPrinterDriverInfo(printer_name));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS)
+#if (BUILDFLAG(IS_BSD) || BUILDFLAG(IS_LINUX)) && BUILDFLAG(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {

--- src/3rdparty/chromium/chrome/browser/printing/printer_query.cc.orig	2023-12-12 22:08:45 UTC
+++ src/3rdparty/chromium/chrome/browser/printing/printer_query.cc
@@ -361,7 +361,7 @@ void PrinterQuery::UpdatePrintSettings(base::Value::Di
     crash_key = std::make_unique<crash_keys::ScopedPrinterInfo>(
         print_backend->GetPrinterDriverInfo(printer_name));
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(USE_CUPS)
+#if (BUILDFLAG(IS_BSD) || BUILDFLAG(IS_LINUX)) && BUILDFLAG(USE_CUPS)
     PrinterBasicInfo basic_info;
     if (print_backend->GetPrinterBasicInfo(printer_name, &basic_info) ==
         mojom::ResultCode::kSuccess) {

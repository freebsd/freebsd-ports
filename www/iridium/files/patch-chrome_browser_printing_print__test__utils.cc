--- chrome/browser/printing/print_test_utils.cc.orig	2026-02-16 10:45:29 UTC
+++ chrome/browser/printing/print_test_utils.cc
@@ -130,7 +130,7 @@ std::unique_ptr<PrintSettings> MakeUserModifiedPrintSe
     data.Set(kMacSystemPrintDialogDataPrintSettings,
              base::Value::BlobStorage({0xB2}));
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     data.Set(kLinuxSystemPrintDialogDataPrinter, printer_name);
     data.Set(kLinuxSystemPrintDialogDataPrintSettings, "print-settings");
     data.Set(kLinuxSystemPrintDialogDataPageSetup, "page-setup");

--- src/3rdparty/chromium/printing/printing_context_linux.cc.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/printing/printing_context_linux.cc
@@ -19,7 +19,7 @@
 #include "printing/units.h"
 
 // Avoid using LinuxUi on Fuchsia.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -68,7 +68,7 @@ mojom::ResultCode PrintingContextLinux::UseDefaultSett
 
   ResetSettings();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::LinuxUi::instance())
     return mojom::ResultCode::kSuccess;
 
@@ -84,7 +84,7 @@ mojom::ResultCode PrintingContextLinux::UseDefaultSett
 }
 
 gfx::Size PrintingContextLinux::GetPdfPaperSizeDeviceUnits() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (ui::LinuxUi::instance())
     return ui::LinuxUi::instance()->GetPdfPaperSize(this);
 #endif
@@ -97,7 +97,7 @@ mojom::ResultCode PrintingContextLinux::UpdatePrinterS
   DCHECK(!printer_settings.show_system_dialog);
   DCHECK(!in_print_job_);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (!ui::LinuxUi::instance())
     return mojom::ResultCode::kSuccess;
 

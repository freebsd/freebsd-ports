--- ui/linux/linux_ui.cc.orig	2026-09-24 17:21:42 UTC
+++ ui/linux/linux_ui.cc
@@ -40,7 +40,7 @@ PrintingContextLinuxDelegate* PrintingCo
 
 // static
 LinuxUi* LinuxUi::SetInstance(LinuxUi* instance) {
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(ENABLE_PRINTING)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(ENABLE_PRINTING)
   PrintingContextLinuxDelegate::SetInstance(instance);
 #endif
 

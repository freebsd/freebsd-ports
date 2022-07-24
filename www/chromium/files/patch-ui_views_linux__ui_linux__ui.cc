--- ui/views/linux_ui/linux_ui.cc.orig	2022-07-22 17:30:31 UTC
+++ ui/views/linux_ui/linux_ui.cc
@@ -27,7 +27,7 @@ void LinuxUI::SetInstance(std::unique_ptr<LinuxUI> ins
   g_linux_ui = instance.release();
 
   SkiaFontDelegate::SetInstance(g_linux_ui);
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
   ShellDialogLinux::SetInstance(g_linux_ui);
 #endif
   ui::SetTextEditKeyBindingsDelegate(g_linux_ui);

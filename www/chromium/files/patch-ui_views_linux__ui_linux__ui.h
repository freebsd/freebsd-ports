--- ui/views/linux_ui/linux_ui.h.orig	2022-07-22 17:30:31 UTC
+++ ui/views/linux_ui/linux_ui.h
@@ -23,7 +23,7 @@
 #include "ui/views/controls/button/button.h"
 #include "ui/views/views_export.h"
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
 #include "ui/shell_dialogs/shell_dialog_linux.h"
 #endif
 
@@ -56,7 +56,7 @@ class WindowFrameProvider;
 // project that wants to do linux desktop native rendering.
 class VIEWS_EXPORT LinuxUI : public ui::LinuxInputMethodContextFactory,
                              public gfx::SkiaFontDelegate,
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CASTOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CASTOS)
                              public ui::ShellDialogLinux,
 #endif
                              public ui::TextEditKeyBindingsDelegateAuraLinux,

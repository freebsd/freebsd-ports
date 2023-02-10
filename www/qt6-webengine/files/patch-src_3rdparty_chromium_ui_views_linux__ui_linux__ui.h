--- src/3rdparty/chromium/ui/views/linux_ui/linux_ui.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/views/linux_ui/linux_ui.h
@@ -21,7 +21,7 @@
 #include "ui/views/controls/button/button.h"
 #include "ui/views/views_export.h"
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMECAST)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMECAST)
 #include "ui/shell_dialogs/shell_dialog_linux.h"
 #endif
 
@@ -57,7 +57,7 @@ class VIEWS_EXPORT LinuxUI : public ui::LinuxInputMeth
 // project that wants to do linux desktop native rendering.
 class VIEWS_EXPORT LinuxUI : public ui::LinuxInputMethodContextFactory,
                              public gfx::SkiaFontDelegate,
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMECAST)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMECAST)
                              public ui::ShellDialogLinux,
 #endif
                              public ui::TextEditKeyBindingsDelegateAuraLinux,

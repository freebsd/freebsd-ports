--- ui/gfx/font_render_params_linux.cc.orig	2025-01-25 09:34:31 UTC
+++ ui/gfx/font_render_params_linux.cc
@@ -24,7 +24,7 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -211,7 +211,7 @@ FontRenderParams GetFontRenderParams(const FontRenderP
 
   // Start with the delegate's settings, but let Fontconfig have the final say.
   FontRenderParams params;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     params = linux_ui->GetDefaultFontRenderParams();
   }

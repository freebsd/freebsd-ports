--- src/3rdparty/chromium/ui/gfx/font_render_params_linux.cc.orig	2022-08-31 12:19:35 UTC
+++ src/3rdparty/chromium/ui/gfx/font_render_params_linux.cc
@@ -25,7 +25,7 @@
 #include "ui/gfx/linux/fontconfig_util.h"
 #include "ui/gfx/switches.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -212,7 +212,7 @@ FontRenderParams GetFontRenderParams(const FontRenderP
 
   // Start with the delegate's settings, but let Fontconfig have the final say.
   FontRenderParams params;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (const auto* linux_ui = ui::LinuxUi::instance())
     params = linux_ui->GetDefaultFontRenderParams();
 #endif

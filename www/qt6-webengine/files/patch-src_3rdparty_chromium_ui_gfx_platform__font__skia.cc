--- src/3rdparty/chromium/ui/gfx/platform_font_skia.cc.orig	2022-08-31 12:19:35 UTC
+++ src/3rdparty/chromium/ui/gfx/platform_font_skia.cc
@@ -28,7 +28,7 @@
 #include "ui/gfx/system_fonts_win.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -166,7 +166,7 @@ void PlatformFontSkia::EnsuresDefaultFontIsInitialized
   weight = system_font.GetWeight();
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // On Linux, LinuxUi is used to query the native toolkit (e.g.
   // GTK) for the default UI font.
   if (const auto* linux_ui = ui::LinuxUi::instance()) {

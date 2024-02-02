--- ui/base/x/x11_display_manager.cc.orig	2024-01-30 07:53:34 UTC
+++ ui/base/x/x11_display_manager.cc
@@ -15,7 +15,7 @@
 #include "ui/gfx/x/randr.h"
 #include "ui/gfx/x/xproto.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -91,7 +91,7 @@ void XDisplayManager::FetchDisplayList() {
           ? display::Display::GetForcedDeviceScaleFactor()
           : 1.0f};
   const auto* display_config = &empty_display_config;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (const auto* linux_ui = ui::LinuxUi::instance()) {
     display_config = &linux_ui->display_config();
   }

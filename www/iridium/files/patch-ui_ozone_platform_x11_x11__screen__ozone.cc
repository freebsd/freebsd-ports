--- ui/ozone/platform/x11/x11_screen_ozone.cc.orig	2023-11-22 14:00:11 UTC
+++ ui/ozone/platform/x11/x11_screen_ozone.cc
@@ -22,7 +22,7 @@
 #include "ui/ozone/platform/x11/x11_window.h"
 #include "ui/ozone/platform/x11/x11_window_manager.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -77,7 +77,7 @@ X11ScreenOzone::X11ScreenOzone()
       window_manager_(X11WindowManager::GetInstance()),
       x11_display_manager_(std::make_unique<XDisplayManager>(this)) {
   DCHECK(window_manager_);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     display_scale_factor_observer_.Observe(linux_ui);
   }

--- ui/aura/screen_ozone.cc.orig	2022-08-15 13:11:31 UTC
+++ ui/aura/screen_ozone.cc
@@ -4,6 +4,8 @@
 
 #include "ui/aura/screen_ozone.h"
 
+#include <memory>
+
 #include "ui/aura/client/screen_position_client.h"
 #include "ui/aura/window.h"
 #include "ui/aura/window_tree_host.h"
@@ -107,9 +109,17 @@ display::Display ScreenOzone::GetPrimaryDisplay() cons
   return platform_screen_->GetPrimaryDisplay();
 }
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
-bool ScreenOzone::SetScreenSaverSuspended(bool suspend) {
-  return platform_screen_->SetScreenSaverSuspended(suspend);
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+ScreenOzone::ScreenSaverSuspenderOzone::ScreenSaverSuspenderOzone(
+    std::unique_ptr<ui::PlatformScreen::PlatformScreenSaverSuspender> suspender)
+    : suspender_(std::move(suspender)) {}
+
+ScreenOzone::ScreenSaverSuspenderOzone::~ScreenSaverSuspenderOzone() = default;
+
+std::unique_ptr<display::Screen::ScreenSaverSuspender>
+ScreenOzone::SuspendScreenSaver() {
+  return std::make_unique<ScreenSaverSuspenderOzone>(
+      platform_screen_->SuspendScreenSaver());
 }
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
 

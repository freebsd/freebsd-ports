--- src/ui/aura/screen_ozone.cc.orig	2026-10-18 18:43:23 UTC
+++ src/ui/aura/screen_ozone.cc
@@ -107,7 +107,7 @@ display::Display ScreenOzone::GetPrimary
   return platform_screen_->GetPrimaryDisplay();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 ScreenOzone::ScreenSaverSuspenderOzone::ScreenSaverSuspenderOzone(
     std::unique_ptr<ui::PlatformScreen::PlatformScreenSaverSuspender> suspender)
     : suspender_(std::move(suspender)) {}

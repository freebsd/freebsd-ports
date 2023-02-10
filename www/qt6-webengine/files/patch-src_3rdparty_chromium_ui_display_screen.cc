--- src/3rdparty/chromium/ui/display/screen.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/display/screen.cc
@@ -72,7 +72,7 @@ void Screen::SetDisplayForNewWindows(int64_t display_i
   display_id_for_new_windows_ = display_id;
 }
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::unique_ptr<Screen::ScreenSaverSuspender> Screen::SuspendScreenSaver() {
   SetScreenSaverSuspended(true);
   screen_saver_suspension_count_++;

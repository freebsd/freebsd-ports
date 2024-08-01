--- ui/display/screen.cc.orig	2024-08-01 05:47:53 UTC
+++ ui/display/screen.cc
@@ -86,7 +86,7 @@ void Screen::SetDisplayForNewWindows(int64_t display_i
   display_id_for_new_windows_ = display_id;
 }
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 Screen::ScreenSaverSuspender::~ScreenSaverSuspender() = default;
 
 std::unique_ptr<Screen::ScreenSaverSuspender> Screen::SuspendScreenSaver() {

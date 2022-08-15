--- ui/display/screen.cc.orig	2022-08-15 13:11:31 UTC
+++ ui/display/screen.cc
@@ -84,27 +84,12 @@ void Screen::SetDisplayForNewWindows(int64_t display_i
   display_id_for_new_windows_ = display_id;
 }
 
-#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
-std::unique_ptr<Screen::ScreenSaverSuspender> Screen::SuspendScreenSaver() {
-  SetScreenSaverSuspended(true);
-  screen_saver_suspension_count_++;
-  return base::WrapUnique(new Screen::ScreenSaverSuspender(this));
-}
+#if BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
+Screen::ScreenSaverSuspender::~ScreenSaverSuspender() = default;
 
-Screen::ScreenSaverSuspender::~ScreenSaverSuspender() {
-  // Check that this suspender still refers to the active screen. Particularly
-  // in tests, the screen might be destructed before the suspender.
-  if (screen_ == GetScreen()) {
-    screen_->screen_saver_suspension_count_--;
-    if (screen_->screen_saver_suspension_count_ == 0) {
-      screen_->SetScreenSaverSuspended(false);
-    }
-  }
-}
-
-bool Screen::SetScreenSaverSuspended(bool suspend) {
+std::unique_ptr<Screen::ScreenSaverSuspender> Screen::SuspendScreenSaver() {
   NOTIMPLEMENTED_LOG_ONCE();
-  return false;
+  return nullptr;
 }
 #endif  // BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_LINUX)
 

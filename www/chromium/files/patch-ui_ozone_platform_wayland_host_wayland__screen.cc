--- ui/ozone/platform/wayland/host/wayland_screen.cc.orig	2022-08-15 13:11:31 UTC
+++ ui/ozone/platform/wayland/host/wayland_screen.cc
@@ -327,6 +327,37 @@ display::Display WaylandScreen::GetDisplayMatching(
   return display_matching ? *display_matching : GetPrimaryDisplay();
 }
 
+std::unique_ptr<WaylandScreen::WaylandScreenSaverSuspender>
+WaylandScreen::WaylandScreenSaverSuspender::Create(WaylandScreen& screen) {
+  auto suspender = base::WrapUnique(new WaylandScreenSaverSuspender(screen));
+  if (suspender->is_suspending_) {
+    screen.screen_saver_suspension_count_++;
+    return suspender;
+  }
+
+  return nullptr;
+}
+
+WaylandScreen::WaylandScreenSaverSuspender::WaylandScreenSaverSuspender(
+    WaylandScreen& screen)
+    : screen_(screen.GetWeakPtr()) {
+  is_suspending_ = screen.SetScreenSaverSuspended(true);
+}
+
+WaylandScreen::WaylandScreenSaverSuspender::~WaylandScreenSaverSuspender() {
+  if (screen_ && is_suspending_) {
+    screen_->screen_saver_suspension_count_--;
+    if (screen_->screen_saver_suspension_count_ == 0) {
+      screen_->SetScreenSaverSuspended(false);
+    }
+  }
+}
+
+std::unique_ptr<PlatformScreen::PlatformScreenSaverSuspender>
+WaylandScreen::SuspendScreenSaver() {
+  return WaylandScreenSaverSuspender::Create(*this);
+}
+
 bool WaylandScreen::SetScreenSaverSuspended(bool suspend) {
   if (!connection_->zwp_idle_inhibit_manager())
     return false;

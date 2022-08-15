--- ui/ozone/platform/x11/x11_screen_ozone.cc.orig	2022-08-15 13:11:31 UTC
+++ ui/ozone/platform/x11/x11_screen_ozone.cc
@@ -4,6 +4,8 @@
 
 #include "ui/ozone/platform/x11/x11_screen_ozone.h"
 
+#include <memory>
+
 #include "base/containers/flat_set.h"
 #include "ui/base/linux/linux_desktop.h"
 #include "ui/base/x/x11_idle_query.h"
@@ -135,8 +137,29 @@ display::Display X11ScreenOzone::GetDisplayMatching(
   return matching_display ? *matching_display : GetPrimaryDisplay();
 }
 
-bool X11ScreenOzone::SetScreenSaverSuspended(bool suspend) {
-  return SuspendX11ScreenSaver(suspend);
+X11ScreenOzone::X11ScreenSaverSuspender::X11ScreenSaverSuspender() {
+  is_suspending_ = SuspendX11ScreenSaver(true);
+}
+
+std::unique_ptr<X11ScreenOzone::X11ScreenSaverSuspender>
+X11ScreenOzone::X11ScreenSaverSuspender::Create() {
+  auto suspender = base::WrapUnique(new X11ScreenSaverSuspender());
+  if (suspender->is_suspending_) {
+    return suspender;
+  }
+
+  return nullptr;
+}
+
+X11ScreenOzone::X11ScreenSaverSuspender::~X11ScreenSaverSuspender() {
+  if (is_suspending_) {
+    SuspendX11ScreenSaver(false);
+  }
+}
+
+std::unique_ptr<PlatformScreen::PlatformScreenSaverSuspender>
+X11ScreenOzone::SuspendScreenSaver() {
+  return X11ScreenSaverSuspender::Create();
 }
 
 bool X11ScreenOzone::IsScreenSaverActive() const {

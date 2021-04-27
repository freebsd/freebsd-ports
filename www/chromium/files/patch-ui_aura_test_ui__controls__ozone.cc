--- ui/aura/test/ui_controls_ozone.cc.orig	2021-04-14 18:41:37 UTC
+++ ui/aura/test/ui_controls_ozone.cc
@@ -349,7 +349,7 @@ bool UIControlsOzone::ScreenDIPToHostPixels(gfx::Point
 // To avoid multiple definitions when use_x11 && use_ozone is true, disable this
 // factory method for OS_LINUX as Linux has a factory method that decides what
 // UIControls to use based on IsUsingOzonePlatform feature flag.
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 ui_controls::UIControlsAura* CreateUIControlsAura(WindowTreeHost* host) {
   return new UIControlsOzone(host);
 }

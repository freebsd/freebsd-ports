--- ui/views/widget/desktop_aura/desktop_screen_ozone.cc.orig	2021-07-19 18:45:44 UTC
+++ ui/views/widget/desktop_aura/desktop_screen_ozone.cc
@@ -28,7 +28,7 @@ gfx::NativeWindow DesktopScreenOzone::GetNativeWindowF
 // To avoid multiple definitions when use_x11 && use_ozone is true, disable this
 // factory method for OS_LINUX as Linux has a factory method that decides what
 // screen to use based on IsUsingOzonePlatform feature flag.
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 std::unique_ptr<display::Screen> CreateDesktopScreen() {
   return std::make_unique<aura::ScreenOzone>();
 }

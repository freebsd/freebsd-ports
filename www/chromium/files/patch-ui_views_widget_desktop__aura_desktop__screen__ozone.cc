--- ui/views/widget/desktop_aura/desktop_screen_ozone.cc.orig	2021-12-14 11:45:40 UTC
+++ ui/views/widget/desktop_aura/desktop_screen_ozone.cc
@@ -25,7 +25,7 @@ gfx::NativeWindow DesktopScreenOzone::GetNativeWindowF
       widget);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_BSD)
 std::unique_ptr<display::Screen> CreateDesktopScreen() {
   auto screen = std::make_unique<aura::ScreenOzone>();
   screen->Initialize();

--- src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_screen_ozone.cc.orig	2023-03-28 19:45:02 UTC
+++ src/3rdparty/chromium/ui/views/widget/desktop_aura/desktop_screen_ozone.cc
@@ -25,7 +25,7 @@ gfx::NativeWindow DesktopScreenOzone::GetNativeWindowF
       widget);
 }
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 std::unique_ptr<display::Screen> CreateDesktopScreen() {
   auto screen = std::make_unique<DesktopScreenOzone>();
   screen->Initialize();

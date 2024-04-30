--- src/3rdparty/chromium/ui/ozone/platform/x11/x11_screen_ozone.cc.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/x11/x11_screen_ozone.cc
@@ -235,7 +235,7 @@ base::Value::List X11ScreenOzone::GetGpuExtraInfo(
   return result;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void X11ScreenOzone::SetDisplayConfig(const DisplayConfig& display_config) {
   display_config_ = &display_config;
   // See DesktopScreenLinux, which sets the |device_scale_factor| before |this|

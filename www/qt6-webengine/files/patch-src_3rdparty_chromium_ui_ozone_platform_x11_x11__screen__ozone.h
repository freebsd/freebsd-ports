--- src/3rdparty/chromium/ui/ozone/platform/x11/x11_screen_ozone.h.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/x11/x11_screen_ozone.h
@@ -61,7 +61,7 @@ class X11ScreenOzone : public PlatformScreen,
   std::string GetCurrentWorkspace() override;
   base::Value::List GetGpuExtraInfo(
       const gfx::GpuExtraInfo& gpu_extra_info) override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetDisplayConfig(const DisplayConfig& display_config) override;
 #endif
 

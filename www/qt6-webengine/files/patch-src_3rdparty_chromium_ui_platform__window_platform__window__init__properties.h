--- src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h
@@ -54,7 +54,7 @@ class ScenicWindowDelegate;
 class ScenicWindowDelegate;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -114,7 +114,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW) PlatformWindo
 
   PlatformWindowShadowType shadow_type = PlatformWindowShadowType::kDefault;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool prefer_dark_theme = false;
   gfx::ImageSkia* icon = nullptr;
   absl::optional<int> background_color;

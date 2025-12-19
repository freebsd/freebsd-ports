--- src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/platform_window/platform_window_init_properties.h
@@ -56,7 +56,7 @@ class ScenicWindowDelegate;
 class ScenicWindowDelegate;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -121,7 +121,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW) PlatformWindo
 
   PlatformWindowShadowType shadow_type = PlatformWindowShadowType::kDefault;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool prefer_dark_theme = false;
   raw_ptr<gfx::ImageSkia> icon = nullptr;
   std::optional<SkColor> background_color;

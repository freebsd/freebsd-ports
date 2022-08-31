--- ui/platform_window/platform_window_init_properties.h.orig	2022-08-31 12:19:35 UTC
+++ ui/platform_window/platform_window_init_properties.h
@@ -54,7 +54,7 @@ class WorkspaceExtensionDelegate;
 class ScenicWindowDelegate;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -115,7 +115,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW) PlatformWindo
 
   PlatformWindowShadowType shadow_type = PlatformWindowShadowType::kDefault;
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool prefer_dark_theme = false;
   raw_ptr<gfx::ImageSkia> icon = nullptr;
   absl::optional<int> background_color;

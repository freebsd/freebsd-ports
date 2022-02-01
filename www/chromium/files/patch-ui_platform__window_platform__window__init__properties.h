--- ui/platform_window/platform_window_init_properties.h.orig	2021-12-31 00:58:32 UTC
+++ ui/platform_window/platform_window_init_properties.h
@@ -52,7 +52,7 @@ class WorkspaceExtensionDelegate;
 class ScenicWindowDelegate;
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -111,7 +111,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW) PlatformWindo
 
   PlatformWindowShadowType shadow_type = PlatformWindowShadowType::kDefault;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   bool prefer_dark_theme = false;
   gfx::ImageSkia* icon = nullptr;
   absl::optional<int> background_color;

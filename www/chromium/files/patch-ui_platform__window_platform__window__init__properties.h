--- ui/platform_window/platform_window_init_properties.h.orig	2020-02-24 18:40:16 UTC
+++ ui/platform_window/platform_window_init_properties.h
@@ -41,7 +41,7 @@ enum class PlatformWindowOpacity {
 
 class WorkspaceExtensionDelegate;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 class X11ExtensionDelegate;
 #endif
 
@@ -82,7 +82,7 @@ struct COMPONENT_EXPORT(PLATFORM_WINDOW) PlatformWindo
 
   WorkspaceExtensionDelegate* workspace_extension_delegate = nullptr;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool prefer_dark_theme = false;
   gfx::ImageSkia* icon = nullptr;
   base::Optional<int> background_color;

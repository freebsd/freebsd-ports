--- ui/platform_window/platform_window_init_properties.h.orig	2019-10-30 16:37:28 UTC
+++ ui/platform_window/platform_window_init_properties.h
@@ -73,7 +73,7 @@ struct PlatformWindowInitProperties {
   bool remove_standard_frame = false;
   std::string workspace;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   bool prefer_dark_theme = false;
   gfx::ImageSkia* icon = nullptr;
   base::Optional<int> background_color;

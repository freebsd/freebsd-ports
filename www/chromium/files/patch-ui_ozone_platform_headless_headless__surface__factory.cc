--- ui/ozone/platform/headless/headless_surface_factory.cc.orig	2024-08-26 12:06:38 UTC
+++ ui/ozone/platform/headless/headless_surface_factory.cc
@@ -34,7 +34,7 @@
 #include "ui/ozone/platform/headless/headless_window_manager.h"
 #include "ui/ozone/public/surface_ozone_canvas.h"
 
-#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA))
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD))
 #include "ui/ozone/platform/headless/vulkan_implementation_headless.h"
 #endif
 
@@ -280,7 +280,7 @@ std::unique_ptr<gpu::VulkanImplementation>
 HeadlessSurfaceFactory::CreateVulkanImplementation(
     bool use_swiftshader,
     bool allow_protected_memory) {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return std::make_unique<VulkanImplementationHeadless>(use_swiftshader);
 #else
   return nullptr;

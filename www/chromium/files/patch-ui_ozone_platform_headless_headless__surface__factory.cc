--- ui/ozone/platform/headless/headless_surface_factory.cc.orig	2022-07-22 17:30:31 UTC
+++ ui/ozone/platform/headless/headless_surface_factory.cc
@@ -34,7 +34,7 @@
 #include "ui/ozone/platform/headless/headless_window_manager.h"
 #include "ui/ozone/public/surface_ozone_canvas.h"
 
-#if BUILDFLAG(ENABLE_VULKAN) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "ui/ozone/platform/headless/vulkan_implementation_headless.h"
 #endif
 
@@ -274,7 +274,7 @@ void HeadlessSurfaceFactory::CheckBasePath() const {
     PLOG(FATAL) << "Unable to write to output location";
 }
 
-#if BUILDFLAG(ENABLE_VULKAN) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 std::unique_ptr<gpu::VulkanImplementation>
 HeadlessSurfaceFactory::CreateVulkanImplementation(
     bool use_swiftshader,

--- ui/ozone/platform/headless/headless_surface_factory.cc.orig	2022-04-21 18:48:31 UTC
+++ ui/ozone/platform/headless/headless_surface_factory.cc
@@ -35,7 +35,7 @@
 #include "ui/ozone/platform/headless/headless_window_manager.h"
 #include "ui/ozone/public/surface_ozone_canvas.h"
 
-#if BUILDFLAG(ENABLE_VULKAN) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 #include "ui/ozone/platform/headless/vulkan_implementation_headless.h"
 #endif
 
@@ -282,7 +282,7 @@ void HeadlessSurfaceFactory::CheckBasePath() const {
     PLOG(FATAL) << "Unable to write to output location";
 }
 
-#if BUILDFLAG(ENABLE_VULKAN) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 std::unique_ptr<gpu::VulkanImplementation>
 HeadlessSurfaceFactory::CreateVulkanImplementation(
     bool use_swiftshader,

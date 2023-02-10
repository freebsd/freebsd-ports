--- src/3rdparty/chromium/ui/ozone/platform/headless/headless_surface_factory.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/headless/headless_surface_factory.h
@@ -26,7 +26,7 @@ class HeadlessSurfaceFactory : public SurfaceFactoryOz
   // SurfaceFactoryOzone:
   std::vector<gl::GLImplementationParts> GetAllowedGLImplementations() override;
   GLOzone* GetGLOzone(const gl::GLImplementationParts& implementation) override;
-#if BUILDFLAG(ENABLE_VULKAN) && BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(ENABLE_VULKAN) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
   std::unique_ptr<gpu::VulkanImplementation> CreateVulkanImplementation(
       bool use_swiftshader,
       bool allow_protected_memory) override;

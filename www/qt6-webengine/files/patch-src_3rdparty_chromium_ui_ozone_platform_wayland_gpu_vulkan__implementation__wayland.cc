--- src/3rdparty/chromium/ui/ozone/platform/wayland/gpu/vulkan_implementation_wayland.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/wayland/gpu/vulkan_implementation_wayland.cc
@@ -38,7 +38,11 @@ bool VulkanImplementationWayland::InitializeVulkanInst
 
     path = path.Append("libvk_swiftshader.so");
   } else {
+#if BUILDFLAG(IS_BSD)
+    path = base::FilePath("libvulkan.so");
+#else
     path = base::FilePath("libvulkan.so.1");
+#endif
   }
 
   return vulkan_instance_.Initialize(path, required_extensions, {});

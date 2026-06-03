--- ui/ozone/platform/wayland/gpu/vulkan_implementation_wayland.cc.orig	2025-09-10 13:22:16 UTC
+++ ui/ozone/platform/wayland/gpu/vulkan_implementation_wayland.cc
@@ -39,7 +39,11 @@ bool VulkanImplementationWayland::InitializeVulkanInst
 
     path = path.Append("libvk_swiftshader.so");
   } else {
+#if BUILDFLAG(IS_BSD)
+    path = base::FilePath("libvulkan.so");
+#else
     path = base::FilePath("libvulkan.so.1");
+#endif
   }
 
   return vulkan_instance_.Initialize(path, required_extensions, {});

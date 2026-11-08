--- ui/ozone/platform/x11/vulkan_implementation_x11.cc.orig	2024-03-22 08:19:40 UTC
+++ ui/ozone/platform/x11/vulkan_implementation_x11.cc
@@ -59,7 +59,11 @@ bool VulkanImplementationX11::InitializeVulkanInstance
 
     path = path.Append("libvk_swiftshader.so");
   } else {
+#if BUILDFLAG(IS_BSD) 
+    path = base::FilePath("libvulkan.so");
+#else
     path = base::FilePath("libvulkan.so.1");
+#endif
   }
 
   return vulkan_instance_.Initialize(path, required_extensions, {});

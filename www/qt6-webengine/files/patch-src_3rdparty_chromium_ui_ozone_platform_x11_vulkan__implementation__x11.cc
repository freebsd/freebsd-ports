--- src/3rdparty/chromium/ui/ozone/platform/x11/vulkan_implementation_x11.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/ozone/platform/x11/vulkan_implementation_x11.cc
@@ -58,7 +58,11 @@ bool VulkanImplementationX11::InitializeVulkanInstance
 
     path = path.Append("libvk_swiftshader.so");
   } else {
+#if BUILDFLAG(IS_BSD) 
+    path = base::FilePath("libvulkan.so");
+#else
     path = base::FilePath("libvulkan.so.1");
+#endif
   }
 
   return vulkan_instance_.Initialize(path, required_extensions, {});

--- gpu/vulkan/vulkan_device_queue.cc.orig	2022-01-21 13:34:10 UTC
+++ gpu/vulkan/vulkan_device_queue.cc
@@ -80,7 +80,7 @@ bool VulkanDeviceQueue::Initialize(
 
       // In dual-CPU cases, we cannot detect the active GPU correctly on Linux,
       // so don't select GPU device based on the |gpu_info|.
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
     // If gpu_info is provided, the device should match it.
     if (gpu_info && (device_properties.vendorID != gpu_info->gpu.vendor_id ||
                      device_properties.deviceID != gpu_info->gpu.device_id)) {

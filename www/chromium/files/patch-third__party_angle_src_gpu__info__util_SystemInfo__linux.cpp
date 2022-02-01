--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2021-12-14 11:47:03 UTC
+++ third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp
@@ -71,6 +71,15 @@ bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo
 
 bool GetSystemInfo(SystemInfo *info)
 {
+#if defined(__FreeBSD__)
+    if (!CollectMesaCardInfo(&(info->gpus)))
+    {
+        if (!GetPCIDevicesFreeBSD(&(info->gpus)))
+        {
+            return GetSystemInfoVulkan(info);
+        }
+    }
+#else
     if (!GetPCIDevicesWithLibPCI(&(info->gpus)))
     {
 #if defined(ANGLE_HAS_VULKAN_SYSTEM_INFO)
@@ -80,6 +89,7 @@ bool GetSystemInfo(SystemInfo *info)
         return false;
 #endif  // defined(ANGLE_HAS_VULKAN_SYSTEM_INFO)
     }
+#endif
 
     if (info->gpus.size() == 0)
     {

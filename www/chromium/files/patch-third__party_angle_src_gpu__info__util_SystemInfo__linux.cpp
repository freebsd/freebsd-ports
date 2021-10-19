--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2021-10-01 01:38:41 UTC
+++ third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp
@@ -71,10 +71,20 @@ bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo
 
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
         return false;
     }
+#endif
 
     if (info->gpus.size() == 0)
     {

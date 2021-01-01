--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2019-03-11 22:07:59 UTC
+++ third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp
@@ -71,10 +71,18 @@ bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo
 
 bool GetSystemInfo(SystemInfo *info)
 {
+#if defined(__FreeBSD__)
+    if (!CollectMesaCardInfo(&(info->gpus)))
+    {
+        if (!GetPCIDevicesFreeBSD(&(info->gpus)))
+            return false;
+    }
+#else
     if (!GetPCIDevicesWithLibPCI(&(info->gpus)))
     {
         return false;
     }
+#endif
 
     if (info->gpus.size() == 0)
     {

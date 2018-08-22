--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2018-08-08 12:13:09.000000000 -0700
+++ third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp	2018-08-20 09:50:36.331947000 -0700
@@ -71,10 +71,18 @@
 
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

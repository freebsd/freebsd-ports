--- third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp.orig	2017-09-10 02:34:01.568975000 +0200
+++ third_party/angle/src/gpu_info_util/SystemInfo_linux.cpp	2017-09-10 02:35:52.870068000 +0200
@@ -71,10 +71,17 @@
 
 bool GetSystemInfo(SystemInfo *info)
 {
+#if defined(__FreeBSD__)
+    if (!CollectMesaCardInfo(&(info->gpus)))
+    {
+        return false;
+    }
+#else
     if (!GetPCIDevicesWithLibPCI(&(info->gpus)))
     {
         return false;
     }
+#endif
 
     if (info->gpus.size() == 0)
     {

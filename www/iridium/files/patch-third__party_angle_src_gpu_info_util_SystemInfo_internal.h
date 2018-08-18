--- third_party/angle/src/gpu_info_util/SystemInfo_internal.h.orig	2017-09-10 02:31:40.635170000 +0200
+++ third_party/angle/src/gpu_info_util/SystemInfo_internal.h	2017-09-10 02:32:27.153701000 +0200
@@ -14,6 +14,8 @@
 namespace angle
 {
 
+bool CollectMesaCardInfo(std::vector<GPUDeviceInfo> *devices);
+
 // Defined in SystemInfo_libpci when GPU_INFO_USE_LIBPCI is defined.
 bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo> *devices);
 // Defined in SystemInfo_x11 when GPU_INFO_USE_X11 is defined.

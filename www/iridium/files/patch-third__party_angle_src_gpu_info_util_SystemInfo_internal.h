--- third_party/angle/src/gpu_info_util/SystemInfo_internal.h.orig	2018-08-08 12:13:09.000000000 -0700
+++ third_party/angle/src/gpu_info_util/SystemInfo_internal.h	2018-08-20 09:43:56.141492000 -0700
@@ -14,8 +14,13 @@
 namespace angle
 {
 
+bool CollectMesaCardInfo(std::vector<GPUDeviceInfo> *devices);
+
 // Defined in SystemInfo_libpci when GPU_INFO_USE_LIBPCI is defined.
 bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo> *devices);
+#if defined(__FreeBSD__)
+bool GetPCIDevicesFreeBSD(std::vector<GPUDeviceInfo> *devices);
+#endif
 // Defined in SystemInfo_x11 when GPU_INFO_USE_X11 is defined.
 bool GetNvidiaDriverVersionWithXNVCtrl(std::string *version);
 

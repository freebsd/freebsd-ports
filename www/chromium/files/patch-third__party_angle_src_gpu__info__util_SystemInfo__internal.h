--- third_party/angle/src/gpu_info_util/SystemInfo_internal.h.orig	2022-02-07 13:39:41 UTC
+++ third_party/angle/src/gpu_info_util/SystemInfo_internal.h
@@ -14,6 +14,10 @@
 namespace angle
 {
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+bool CollectMesaCardInfo(std::vector<GPUDeviceInfo> *devices);                
+#endif
+
 // Defined in SystemInfo_libpci when GPU_INFO_USE_LIBPCI is defined.
 bool GetPCIDevicesWithLibPCI(std::vector<GPUDeviceInfo> *devices);
 // Defined in SystemInfo_x11 when GPU_INFO_USE_X11 is defined.

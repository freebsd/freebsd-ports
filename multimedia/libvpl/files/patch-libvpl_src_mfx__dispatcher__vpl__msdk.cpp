--- libvpl/src/mfx_dispatcher_vpl_msdk.cpp.orig	2025-12-17 23:04:39 UTC
+++ libvpl/src/mfx_dispatcher_vpl_msdk.cpp
@@ -11,7 +11,7 @@
     #include "src/mfx_dispatcher_vpl_win.h"
 #endif
 
-#ifdef __linux__
+#ifdef __unix__
     #include <pthread.h>
     #define strncpy_s(dst, size, src, cnt) strncpy((dst), (src), (cnt)) // NOLINT
 #endif
@@ -97,7 +97,7 @@ static const mfxImplementedFunctions msdkImplFuncs = {
     (mfxChar**)msdkImplFuncsNames
 };
 
-#ifdef __linux__
+#ifdef __unix__
 // optional extBuf to limit threads created in MSDK session creation
 // to enable, set vplParam.NumExtParam and vplParam.ExtParam before calling MFXInitEx2()
 static const mfxExtThreadsParam extThreadParam = {
@@ -142,7 +142,7 @@ mfxStatus LoaderCtxMSDK::OpenSession(mfxSession *sessi
     mfxInitializationParam vplParam = {};
     vplParam.AccelerationMode       = accelMode;
 
-#ifdef __linux__
+#ifdef __unix__
     vplParam.ExtParam    = (mfxExtBuffer **)&extParams;
     vplParam.NumExtParam = 1;
 #else
@@ -183,7 +183,7 @@ mfxStatus LoaderCtxMSDK::GetDefaultAccelType(mfxU32 ad
 }
 
 mfxStatus LoaderCtxMSDK::GetDefaultAccelType(mfxU32 adapterID, mfxIMPL *implDefault, mfxU64 *luid) {
-#ifdef __linux__
+#ifdef __unix__
     // VAAPI only
     *implDefault = MFX_IMPL_VIA_VAAPI;
     *luid        = 0;
@@ -235,7 +235,7 @@ mfxStatus LoaderCtxMSDK::QueryAPIVersion(STRING_TYPE l
         vplParam.AccelerationMode =
             (mfxAccelerationMode)CvtAccelType(MFX_IMPL_HARDWARE, implDefault & 0xFF00);
 
-#ifdef __linux__
+#ifdef __unix__
         vplParam.ExtParam    = (mfxExtBuffer **)&extParams;
         vplParam.NumExtParam = 1;
 #else
@@ -279,7 +279,7 @@ mfxStatus LoaderCtxMSDK::QueryMSDKCaps(STRING_TYPE lib
     m_libNameFull = libNameFull;
     m_deviceID    = 0;
 
-#ifdef __linux__
+#ifdef __unix__
     // require pthreads to be linked in for MSDK RT to load
     pthread_key_t pkey;
     if (pthread_key_create(&pkey, NULL) == 0) {
@@ -504,13 +504,64 @@ mfxU32 read_device_file(std::string &path) {
     return result;
 }
 
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) && __FreeBSD__ < 13
+#include <sys/sysctl.h>
+#else
+#include <sys/ioctl.h>
+#include <fcntl.h>
+#include <unistd.h>
+#endif // defined(__FreeBSD__) && __FreeBSD__ < 13
+
+struct drm_pciinfo {
+	uint16_t        domain;
+	uint8_t         bus;
+	uint8_t         dev;
+	uint8_t         func;
+	uint16_t        vendor_id;
+	uint16_t        device_id;
+	uint16_t        subvendor_id;
+	uint16_t        subdevice_id;
+	uint8_t         revision_id;
+};
+
+#define DRM_IOCTL_BASE         'd'
+#define DRM_IOR(nr,type)       _IOR(DRM_IOCTL_BASE,nr,type)
+#define DRM_IOCTL_GET_PCIINFO  DRM_IOR(0x15, struct drm_pciinfo)
+#endif
+
 mfxStatus LoaderCtxMSDK::GetRenderNodeDescription(mfxU32 adapterID,
                                                   mfxU32 &vendorID,
                                                   mfxU16 &deviceID) {
     vendorID = 0;
     deviceID = 0;
 
-#if defined(__linux__)
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) && __FreeBSD__ < 13
+    std::string mib = "dev.drm." + std::to_string(128 + adapterID) + ".PCI_ID";
+    char pci_id[20];
+    size_t len = sizeof(pci_id);
+    if (sysctlbyname(mib.c_str(), pci_id, &len, NULL, 0))
+	    return MFX_ERR_UNSUPPORTED;
+    sscanf(pci_id, "%x:%x", &vendorID, &deviceID);
+#else
+    std::string path = "/dev/dri/renderD" + std::to_string(128 + adapterID);
+    int fd = open(path.c_str(), O_RDONLY);
+    if (fd == -1)
+	    return MFX_ERR_UNSUPPORTED;
+    struct drm_pciinfo pinfo;
+    if (ioctl(fd, DRM_IOCTL_GET_PCIINFO, &pinfo)) {
+	    close(fd);
+	    return MFX_ERR_UNSUPPORTED;
+    }
+    vendorID = pinfo.vendor_id;
+    deviceID = pinfo.device_id;
+    close(fd);
+#endif // defined(__FreeBSD__) && __FreeBSD__ < 13
+    if (vendorID != 0x8086 || deviceID == 0)
+	    return MFX_ERR_UNSUPPORTED;
+    return MFX_ERR_NONE;
+#elif defined(__linux__)
     mfxU32 DRMRenderNodeNum = 128 + adapterID;
     std::string nodeStr     = std::to_string(DRMRenderNodeNum);
 
@@ -583,7 +634,7 @@ mfxStatus LoaderCtxMSDK::QueryExtDeviceID(mfxExtendedD
             luidArr >>= 8;
         }
     }
-#elif defined(__linux__)
+#elif defined(__unix__)
     extDeviceID->DRMPrimaryNodeNum = adapterID;
     extDeviceID->DRMRenderNodeNum  = 128 + adapterID;
 #endif

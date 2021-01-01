--- third_party/angle/src/gpu_info_util/SystemInfo_x11.cpp.orig	2019-03-11 22:07:59 UTC
+++ third_party/angle/src/gpu_info_util/SystemInfo_x11.cpp
@@ -8,6 +8,8 @@
 
 #include "gpu_info_util/SystemInfo_internal.h"
 
+#include <GL/glx.h>
+#include <GL/glxext.h>
 #include <X11/Xlib.h>
 
 #include "common/debug.h"
@@ -18,8 +20,43 @@
 #    error SystemInfo_x11.cpp compiled without GPU_INFO_USE_X11
 #endif
 
+#define GLX_RENDERER_VENDOR_ID_MESA	0x8183
+#define GLX_RENDERER_DEVICE_ID_MESA	0x8184
+
 namespace angle
 {
+
+bool CollectMesaCardInfo(std::vector<GPUDeviceInfo> *devices)
+{
+
+    unsigned int vid[3], did[3];
+
+    Display *display = XOpenDisplay(NULL);
+    if (!display) {
+        return false;
+    }
+
+    PFNGLXQUERYRENDERERINTEGERMESAPROC queryInteger =
+        (PFNGLXQUERYRENDERERINTEGERMESAPROC) glXGetProcAddressARB((const GLubyte *)
+        "glXQueryRendererIntegerMESA");
+
+    if (!queryInteger)
+        return false;
+
+    bool vendor_ret =
+        queryInteger(display, 0, 0, GLX_RENDERER_VENDOR_ID_MESA, vid);
+    bool device_ret =
+        queryInteger(display, 0, 0, GLX_RENDERER_DEVICE_ID_MESA, did);
+
+    if (vendor_ret && device_ret) {
+        GPUDeviceInfo info;
+        info.vendorId = vid[0];
+        info.deviceId = did[0];
+        devices->push_back(info);
+    }
+
+    return true;
+}
 
 bool GetNvidiaDriverVersionWithXNVCtrl(std::string *version)
 {

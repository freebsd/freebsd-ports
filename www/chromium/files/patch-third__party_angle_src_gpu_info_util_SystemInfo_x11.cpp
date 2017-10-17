--- third_party/angle/src/gpu_info_util/SystemInfo_x11.cpp.orig	2017-09-10 02:37:35.309513000 +0200
+++ third_party/angle/src/gpu_info_util/SystemInfo_x11.cpp	2017-09-10 02:48:01.225261000 +0200
@@ -8,6 +8,8 @@
 
 #include "gpu_info_util/SystemInfo_internal.h"
 
+#include <GL/glx.h>
+#include <GL/glxext.h>
 #include <X11/Xlib.h>
 
 #include "common/debug.h"
@@ -18,8 +20,40 @@
 #error SystemInfo_x11.cpp compiled without GPU_INFO_USE_X11
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
+    bool vendor_ret =
+        queryInteger(display, 0, 0, GLX_RENDERER_VENDOR_ID_MESA, vid);
+    bool_device_ret =
+        queryInteger(display, 0, 0, GLX_RENDERER_DEVICE_ID_MESA, did);
+
+    if (vendor_ret && device_ret) {
+        GPUDeviceInfo info;
+        info.vendorId = vid[0];
+        info.deviceId = did[0];
+        device->push_back(info);
+    }
+
+    return true;
+}
 
 bool GetNvidiaDriverVersionWithXNVCtrl(std::string *version)
 {

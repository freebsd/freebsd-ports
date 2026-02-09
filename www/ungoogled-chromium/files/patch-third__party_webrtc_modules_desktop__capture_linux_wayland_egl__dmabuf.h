--- third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.h.orig	2026-02-15 10:01:45 UTC
+++ third_party/webrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.h
@@ -16,6 +16,8 @@
 #include <GL/gl.h>
 #include <gbm.h>
 
+#include <sys/types.h>
+
 #include <cstdint>
 #include <map>
 #include <memory>

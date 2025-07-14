commit 505b8f54ca7e3ee3230ed9c94e6553de504fda29
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    avoid linux-only includes

diff --git third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
index 9f30378451fb..75381cd39e29 100644
--- third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
+++ third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -11,12 +11,16 @@
 #include "modules/desktop_capture/linux/wayland/egl_dmabuf.h"
 
 #include <EGL/eglext.h>
+#if !defined(__FreeBSD__)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <gdk/gdk.h>
 #include <libdrm/drm_fourcc.h>
+#if !defined(__FreeBSD__)
 #include <linux/types.h>
+#endif
 #include <spa/param/video/format-utils.h>
 #include <unistd.h>
 #include <xf86drm.h>

commit 3524023ca1d2184ab9a5a7cc61695923e6834cc1
Author: Christoph Moench-Tegeder <cmt@burggraben.net>

    avoid linux-only includes

diff --git third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
index 6a019c64b4b3..18bb43d797dd 100644
--- third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
+++ third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -10,12 +10,16 @@
 
 #include "modules/desktop_capture/linux/wayland/egl_dmabuf.h"
 
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

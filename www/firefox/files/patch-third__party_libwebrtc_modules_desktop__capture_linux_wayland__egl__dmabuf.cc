commit 7ee076ab9ca300348d5662a894bf2d27e6724837
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    avoid linux-only includes

diff --git third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
index c8653928d9e9..d380fc1b22f1 100644
--- third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
+++ third_party/libwebrtc/modules/desktop_capture/linux/wayland/egl_dmabuf.cc
@@ -15,7 +15,9 @@
 #include <EGL/eglplatform.h>
 #include <GL/gl.h>
 #include <GL/glext.h>
+#if !defined(__FreeBSD__)
 #include <asm/ioctl.h>
+#endif
 #include <dlfcn.h>
 #include <fcntl.h>
 #include <gbm.h>
@@ -23,7 +25,9 @@
 #include <libdrm/drm_fourcc.h>
 #include <spa/param/video/raw.h>
 #include <sys/stat.h>
+#if !defined(__FreeBSD__)
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 #include <unistd.h>
 #include <xf86drm.h>

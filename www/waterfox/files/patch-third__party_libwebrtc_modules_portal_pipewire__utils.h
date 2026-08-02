commit 9f34111f6f4e2ebefd878a3c256fc012826e6936
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    FreeBSD does not know asm-generic/ioctl.h

diff --git third_party/libwebrtc/modules/portal/pipewire_utils.h third_party/libwebrtc/modules/portal/pipewire_utils.h
index c3d4f347a8cd..14a36260c292 100644
--- third_party/libwebrtc/modules/portal/pipewire_utils.h
+++ third_party/libwebrtc/modules/portal/pipewire_utils.h
@@ -11,7 +11,9 @@
 #ifndef MODULES_PORTAL_PIPEWIRE_UTILS_H_
 #define MODULES_PORTAL_PIPEWIRE_UTILS_H_
 
+#if !defined(__FreeBSD__)
 #include <asm-generic/ioctl.h>
+#endif
 #include <sys/ioctl.h>
 #include <sys/mman.h>
 

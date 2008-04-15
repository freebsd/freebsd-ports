--- hw/xfree86/os-support/xf86_OSlib.h.orig	2007-08-23 15:04:53.000000000 -0400
+++ hw/xfree86/os-support/xf86_OSlib.h	2008-04-08 16:20:04.000000000 -0400
@@ -495,6 +495,9 @@
 #   if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__DragonFly__)
 #    if defined(__FreeBSD_kernel_version) && (__FreeBSD_kernel_version >= 500013)
 #     include <sys/mouse.h>
+#     if (__FreeBSD_kernel_version >= 700106)
+#      define XPS2_SUPPORT
+#     endif
 #    else
 #     undef MOUSE_GETINFO
 #     include <machine/mouse.h>

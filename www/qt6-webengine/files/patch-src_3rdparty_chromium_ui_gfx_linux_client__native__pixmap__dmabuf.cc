--- src/3rdparty/chromium/ui/gfx/linux/client_native_pixmap_dmabuf.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/gfx/linux/client_native_pixmap_dmabuf.cc
@@ -5,7 +5,9 @@
 #include "ui/gfx/linux/client_native_pixmap_dmabuf.h"
 
 #include <fcntl.h>
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <linux/version.h>
+#endif
 #include <stddef.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
@@ -27,11 +29,7 @@
 #include "ui/gfx/buffer_format_util.h"
 #include "ui/gfx/switches.h"
 
-#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 11, 0)
-#include <linux/dma-buf.h>
-#else
-#include <linux/types.h>
-
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
 struct dma_buf_sync {
   __u64 flags;
 };

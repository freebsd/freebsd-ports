--- ui/gfx/linux/client_native_pixmap_dmabuf.cc.orig	2017-08-02 16:54:46.101075000 +0200
+++ ui/gfx/linux/client_native_pixmap_dmabuf.cc	2017-08-02 16:55:49.754442000 +0200
@@ -5,7 +5,9 @@
 #include "ui/gfx/linux/client_native_pixmap_dmabuf.h"
 
 #include <fcntl.h>
+#if !defined(__FreeBSD__)
 #include <linux/version.h>
+#endif
 #include <stddef.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
@@ -19,11 +21,7 @@
 #include "base/strings/stringprintf.h"
 #include "base/trace_event/trace_event.h"
 
-#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 11, 0)
-#include <linux/dma-buf.h>
-#else
-#include <linux/types.h>
-
+#if defined(__FreeBSD__)
 struct dma_buf_sync {
   __u64 flags;
 };

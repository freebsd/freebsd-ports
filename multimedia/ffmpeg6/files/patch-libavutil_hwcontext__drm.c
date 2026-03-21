drm-kmod doesn't expose uAPI yet, so bundle like Mesa

--- libavutil/hwcontext_drm.c.orig	2022-07-22 17:58:39 UTC
+++ libavutil/hwcontext_drm.c
@@ -28,6 +28,19 @@
 #if HAVE_LINUX_DMA_BUF_H
 #include <linux/dma-buf.h>
 #include <sys/ioctl.h>
+#else // BSDs
+#undef HAVE_LINUX_DMA_BUF_H
+#define HAVE_LINUX_DMA_BUF_H 1
+#include <sys/ioctl.h>
+struct dma_buf_sync {
+	uint64_t flags;
+};
+#define DMA_BUF_BASE		'b'
+#define DMA_BUF_IOCTL_SYNC	_IOW(DMA_BUF_BASE, 0, struct dma_buf_sync)
+#define DMA_BUF_SYNC_READ      (1 << 0)
+#define DMA_BUF_SYNC_WRITE     (2 << 0)
+#define DMA_BUF_SYNC_START     (0 << 2)
+#define DMA_BUF_SYNC_END       (1 << 2)
 #endif
 
 #include <drm.h>

--- media_softlet/linux/common/os/xe/include/dma-buf.h.orig	2026-03-19 10:15:05 UTC
+++ media_softlet/linux/common/os/xe/include/dma-buf.h
@@ -20,7 +20,11 @@
 #ifndef _DMA_BUF_UAPI_H_
 #define _DMA_BUF_UAPI_H_
 
-#include <linux/types.h>
+#if defined(__FreeBSD__)
+    #include "freebsd_compat_linux_types.h"
+#else
+    #include <linux/types.h>
+#endif
 
 /**
  * struct dma_buf_sync - Synchronize with CPU access.

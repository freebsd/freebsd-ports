--- spa/plugins/vulkan/dmabuf_fallback.c.orig	2023-10-06 09:37:06 UTC
+++ spa/plugins/vulkan/dmabuf_fallback.c
@@ -32,11 +32,11 @@ bool dmabuf_import_sync_file(struct spa_log *log, int 
 }
 
 bool dmabuf_import_sync_file(struct spa_log *log, int dmabuf_fd, uint32_t flags, int sync_file_fd) {
-	spa_log_error("DMA-BUF sync_file import IOCTL not available on this system");
+	spa_log_error(log, "DMA-BUF sync_file import IOCTL not available on this system");
 	return false;
 }
 
 int dmabuf_export_sync_file(struct spa_log *log, int dmabuf_fd, uint32_t flags) {
-	spa_log_error("DMA-BUF sync_file export IOCTL not available on this system");
+	spa_log_error(log, "DMA-BUF sync_file export IOCTL not available on this system");
 	return false;
 }

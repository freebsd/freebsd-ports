--- source/ni_nvme.h.orig	2026-10-17 00:01:03 UTC
+++ source/ni_nvme.h
@@ -232,7 +232,17 @@ typedef struct _ni_nvme_identity
   ni_nvme_identity_xcoder_hw_t xcoder_devices[NI_MAX_DEVICES_PER_HW_INSTANCE];
 } ni_nvme_identity_t;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__FreeBSD__)
+/* Linux kernel integer type names used by the passthrough structs below.
+ * FreeBSD nvme(4) implements the same ioctls with an identical layout. */
+#include <sys/ioccom.h>
+typedef uint8_t __u8;
+typedef uint16_t __u16;
+typedef uint32_t __u32;
+typedef uint64_t __u64;
+typedef int64_t __s64;
+#endif
 
 typedef struct _ni_nvme_user_io
 {
@@ -618,7 +628,7 @@ int ni_nvme_enumerate_devices(char ni_devices[][NI_MAX
                               int max_handles);
 
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 int32_t ni_nvme_send_admin_pass_through_command(ni_device_handle_t fd, ni_nvme_passthrough_cmd_t* cmd);
 int32_t ni_nvme_send_io_pass_through_command(ni_device_handle_t fd, ni_nvme_passthrough_cmd_t* cmd);
 #endif
@@ -959,6 +969,28 @@ int32_t ni_nvme_batch_cmd_aio(aio_context_t ctx, ni_io
                                int write);
 int32_t ni_nvme_batch_cmd_aio(aio_context_t ctx, ni_iocb_t **iocbs,
         ni_io_event_t *events, int iocb_num);
+#endif
+
+#ifdef __FreeBSD__
+/* POSIX AIO needs no per-session context: keep the Linux call sites unchanged. */
+static inline int32_t ni_aio_setup(unsigned nr, ni_aio_context_t *ctxp)
+{
+    (void)nr;
+    *ctxp = 1; /* non-zero: "valid", checked by the cleanup code */
+    return 0;
+}
+
+static inline int32_t ni_aio_destroy(ni_aio_context_t ctx)
+{
+    (void)ctx;
+    return 0;
+}
+
+void ni_nvme_setup_aio_iocb(ni_device_handle_t handle, ni_iocb_t *iocb,
+                            void *p_data, uint32_t data_len, uint32_t lba,
+                            int write);
+int32_t ni_nvme_batch_cmd_aio(ni_aio_context_t ctx, ni_iocb_t **iocbs,
+                              ni_io_event_t *events, int iocb_num);
 #endif
 
 #ifdef __cplusplus

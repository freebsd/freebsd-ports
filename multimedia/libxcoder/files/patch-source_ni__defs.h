--- source/ni_defs.h.orig	2026-10-17 00:01:03 UTC
+++ source/ni_defs.h
@@ -31,12 +31,16 @@
 #include <windows.h>
 #include <process.h>
 #include <malloc.h>
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
 #if __linux__
 #include <linux/types.h>
 #include <unistd.h>
 #include <sys/syscall.h>
 #include <linux/aio_abi.h>
+#elif __FreeBSD__
+#include <sys/types.h>
+#include <unistd.h>
+#include <aio.h>
 #endif
 #include <sys/time.h>
 #include <pthread.h>
@@ -191,6 +195,32 @@ typedef struct io_event ni_io_event_t;
 #define KERNEL_NVME_FILE_NAME_MAX_SZ                                           \
     (SYS_PREFIX_SZ + strlen(KERNEL_NVME_MAX_SEG_SZ_PATH) +                     \
      MIN_NVME_DEV_NAME_LEN + 10)
+#define DEFAULT_IO_TRANSFER_SIZE 520192
+#define MAX_IO_TRANSFER_SIZE 3133440
+
+#elif __FreeBSD__
+/* FreeBSD: no Linux AIO (same as the macOS branch); NVMe passthrough uses the
+ * Linux-compatible ioctls of nvme(4). */
+typedef pthread_t ni_pthread_t;
+typedef pthread_mutex_t ni_pthread_mutex_t;
+typedef pthread_cond_t ni_pthread_cond_t;
+typedef pthread_attr_t ni_pthread_attr_t;
+typedef pthread_condattr_t ni_pthread_condattr_t;
+typedef pthread_mutexattr_t ni_pthread_mutexattr_t;
+typedef sigset_t ni_sigset_t;
+typedef int32_t ni_device_handle_t;
+typedef int32_t ni_event_handle_t;
+typedef int32_t ni_lock_handle_t;
+/* POSIX AIO (aio(4)): there is no context object and no event array, results
+ * are read back with aio_error()/aio_return(); the types are kept so the
+ * session context layout does not change. */
+typedef unsigned long ni_aio_context_t;
+typedef struct aiocb ni_iocb_t;
+typedef int ni_io_event_t;
+#define NI_INVALID_DEVICE_HANDLE (-1)
+#define NI_INVALID_EVENT_HANDLE (-1)
+#define NI_INVALID_LOCK_HANDLE (-1)
+#define LIB_API
 #define DEFAULT_IO_TRANSFER_SIZE 520192
 #define MAX_IO_TRANSFER_SIZE 3133440
 

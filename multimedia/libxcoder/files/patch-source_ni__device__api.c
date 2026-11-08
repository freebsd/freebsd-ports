--- source/ni_device_api.c.orig	2026-10-17 00:01:03 UTC
+++ source/ni_device_api.c
@@ -26,7 +26,7 @@
  *          video processing
  ******************************************************************************/
 
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 #define _GNU_SOURCE //O_DIRECT is Linux-specific.  One must define _GNU_SOURCE to obtain its definitions // NOLINT(bugprone-reserved-identifier,cert-dcl37-c,cert-dcl51-cpp)
 #if __linux__
 #include <linux/types.h>
@@ -89,7 +89,7 @@ const char *const g_xcoder_log_names[NI_XCODER_LOG_NAM
     NI_XCODER_LOG_NAME_DEBUG,
     NI_XCODER_LOG_NAME_FULL,
     0};
-#if __linux__ || __APPLE__
+#if __linux__ || __APPLE__ || __FreeBSD__
 static struct stat g_nvme_stat = { 0 };
 
 static int close_fd_zero_atexit = 0;
@@ -457,7 +457,7 @@ NI_DEPRECATED ni_device_handle_t ni_device_open(const 
     {
 #if __linux__
             *p_max_io_size_out = ni_get_kernel_max_io_size(p_dev);
-#elif __APPLE__
+#elif __APPLE__ || __FreeBSD__
             *p_max_io_size_out = MAX_IO_TRANSFER_SIZE;
 #endif
     }
@@ -465,7 +465,7 @@ NI_DEPRECATED ni_device_handle_t ni_device_open(const 
     ni_log(NI_LOG_DEBUG, "%s: opening regular-io enabled %s\n", __func__,
            p_dev);
     //O_SYNC is added to ensure that data is written to the card when the pread/pwrite function returns
-    #if __linux__
+    #if __linux__ || __FreeBSD__
         //O_DIRECT is added to ensure that data can be sent directly to the card instead of to cache memory
         fd = open(p_dev, O_RDWR | O_SYNC | O_DIRECT);
     #elif __APPLE__
@@ -635,7 +635,7 @@ ni_device_handle_t ni_device_open2(const char * p_dev,
     }
 
     open_flags |= O_SYNC;
-#if __linux__
+#if __linux__ || __FreeBSD__
     open_flags |= O_DIRECT;
 #elif __APPLE__
     /* macOS doesn't support O_DIRECT, use F_NOCACHE instead */

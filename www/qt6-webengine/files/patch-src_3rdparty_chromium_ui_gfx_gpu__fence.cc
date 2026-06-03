--- src/3rdparty/chromium/ui/gfx/gpu_fence.cc.orig	2026-01-23 20:06:19.000000000 +0100
+++ src/3rdparty/chromium/ui/gfx/gpu_fence.cc	2026-04-08 13:47:09.206288000 +0200
@@ -9,6 +9,10 @@
 #include "base/time/time.h"
 #include "build/build_config.h"
 
+#if BUILDFLAG(IS_BSD)
+#include <poll.h>
+#endif
+
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 #include <sync/sync.h>
 #endif
@@ -42,7 +46,13 @@
     return;
   }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_BSD)
+  int fd = fence_handle_.Peek();
+  if (fd >= 0) {
+    struct pollfd fds = {fd, POLLIN, 0};
+    poll(&fds, 1, -1);
+  }
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
   static const int kInfiniteSyncWaitTimeout = -1;
   DCHECK_GE(fence_handle_.Peek(), 0);
   if (sync_wait(fence_handle_.Peek(), kInfiniteSyncWaitTimeout) < 0) {
@@ -57,7 +67,10 @@
 GpuFence::FenceStatus GpuFence::GetStatusChangeTime(int fd,
                                                     base::TimeTicks* time) {
   DCHECK_NE(fd, -1);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_BSD)
+  // sync_fence_info is not available on FreeBSD.
+  return FenceStatus::kInvalid;
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
   auto info =
       std::unique_ptr<sync_fence_info_data, void (*)(sync_fence_info_data*)>{
           sync_fence_info(fd), sync_fence_info_free};

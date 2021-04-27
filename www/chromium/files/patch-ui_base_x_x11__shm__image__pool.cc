--- ui/base/x/x11_shm_image_pool.cc.orig	2021-04-14 18:41:37 UTC
+++ ui/base/x/x11_shm_image_pool.cc
@@ -16,6 +16,7 @@
 #include "base/environment.h"
 #include "base/location.h"
 #include "base/strings/string_util.h"
+#include "base/system/sys_info.h"
 #include "base/threading/thread_task_runner_handle.h"
 #include "build/build_config.h"
 #include "build/chromeos_buildflags.h"
@@ -46,10 +47,14 @@ constexpr float kShmResizeShrinkThreshold =
     1.0f / (kShmResizeThreshold * kShmResizeThreshold);
 
 std::size_t MaxShmSegmentSizeImpl() {
+#if defined(OS_BSD)
+  return base::SysInfo::MaxSharedMemorySize();
+#else
   struct shminfo info;
   if (shmctl(0, IPC_INFO, reinterpret_cast<struct shmid_ds*>(&info)) == -1)
     return 0;
   return info.shmmax;
+#endif
 }
 
 std::size_t MaxShmSegmentSize() {

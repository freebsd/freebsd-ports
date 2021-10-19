--- base/debug/stack_trace.cc.orig	2021-09-14 01:51:47 UTC
+++ base/debug/stack_trace.cc
@@ -16,7 +16,7 @@
 #if BUILDFLAG(CAN_UNWIND_WITH_FRAME_POINTERS)
 #include "third_party/abseil-cpp/absl/types/optional.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <pthread.h>
 
 #include "base/process/process_handle.h"

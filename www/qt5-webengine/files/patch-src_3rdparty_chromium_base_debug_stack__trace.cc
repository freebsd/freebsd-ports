--- src/3rdparty/chromium/base/debug/stack_trace.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/debug/stack_trace.cc
@@ -15,7 +15,7 @@
 
 #if BUILDFLAG(CAN_UNWIND_WITH_FRAME_POINTERS)
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_BSD)
 #include <pthread.h>
 #include "base/process/process_handle.h"
 #include "base/threading/platform_thread.h"

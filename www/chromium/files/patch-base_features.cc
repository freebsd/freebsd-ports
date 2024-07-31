--- base/features.cc.orig	2024-07-30 11:12:21 UTC
+++ base/features.cc
@@ -9,8 +9,10 @@
 #include "base/threading/platform_thread.h"
 #include "build/buildflag.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
+#if !BUILDFLAG(IS_BSD)
 #include "base/message_loop/message_pump_epoll.h"
+#endif
 #include "base/message_loop/message_pump_libevent.h"
 #endif
 
@@ -97,9 +99,11 @@ void Init(EmitThreadControllerProfilerMetadata
   sequence_manager::internal::ThreadController::InitializeFeatures(
       emit_thread_controller_profiler_metadata);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   MessagePumpLibevent::InitializeFeatures();
+#if !BUILDFLAG(IS_BSD)
   MessagePumpEpoll::InitializeFeatures();
+#endif
 #endif
 
 #if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_CHROMEOS)

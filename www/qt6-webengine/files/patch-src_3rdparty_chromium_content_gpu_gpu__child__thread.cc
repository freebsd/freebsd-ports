--- src/3rdparty/chromium/content/gpu/gpu_child_thread.cc.orig	2024-07-03 01:14:49 UTC
+++ src/3rdparty/chromium/content/gpu/gpu_child_thread.cc
@@ -59,7 +59,7 @@
 #include "third_party/skia/include/ports/SkFontConfigInterface.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "content/child/sandboxed_process_thread_type_handler.h"
 #endif
 
@@ -148,7 +148,8 @@ void GpuChildThread::Init(const base::TimeTicks& proce
 
   viz_main_.gpu_service()->set_start_time(process_start_time);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+// XXX BSD
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)) && !BUILDFLAG(IS_BSD)
   SandboxedProcessThreadTypeHandler::NotifyMainChildThreadCreated();
 #endif
 

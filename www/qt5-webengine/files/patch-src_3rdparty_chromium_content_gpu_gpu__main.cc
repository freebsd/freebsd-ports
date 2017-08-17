--- src/3rdparty/chromium/content/gpu/gpu_main.cc.orig	2017-04-11 14:08:45 UTC
+++ src/3rdparty/chromium/content/gpu/gpu_main.cc
@@ -99,7 +99,7 @@ void GetGpuInfoFromCommandLine(gpu::GPUInfo& gpu_info,
                                const base::CommandLine& command_line);
 bool WarmUpSandbox(const base::CommandLine& command_line);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD)
 bool CollectGraphicsInfo(gpu::GPUInfo& gpu_info);
 #endif
 
@@ -191,13 +191,13 @@ int GpuMain(const MainFunctionParams& parameters) {
 #else
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_UI);
 #endif
-#elif defined(OS_LINUX) && defined(USE_X11)
+#elif (defined(OS_LINUX)||defined(OS_BSD)) && defined(USE_X11)
   // We need a UI loop so that we can grab the Expose events. See GLSurfaceGLX
   // and https://crbug.com/326995.
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_UI);
   scoped_ptr<ui::PlatformEventSource> event_source =
       ui::PlatformEventSource::CreateDefault();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX)||defined(OS_BSD)
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_DEFAULT);
 #elif defined(OS_MACOSX)
   // This is necessary for CoreAnimation layers hosted in the GPU process to be
@@ -303,7 +303,7 @@ int GpuMain(const MainFunctionParams& parameters) {
       // and we already registered them through SetGpuInfo() above.
       base::TimeTicks before_collect_context_graphics_info =
           base::TimeTicks::Now();
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD)
       if (!CollectGraphicsInfo(gpu_info))
         dead_on_arrival = true;
 
@@ -457,7 +457,7 @@ bool WarmUpSandbox(const base::CommandLine& command_li
   return true;
 }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD)
 bool CollectGraphicsInfo(gpu::GPUInfo& gpu_info) {
   TRACE_EVENT0("gpu,startup", "Collect Graphics Info");
 

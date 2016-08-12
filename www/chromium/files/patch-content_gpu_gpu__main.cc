--- content/gpu/gpu_main.cc.orig	2016-07-22 00:06:54.000000000 -0400
+++ content/gpu/gpu_main.cc	2016-08-03 12:37:05.590978000 -0400
@@ -102,7 +102,7 @@
                                const base::CommandLine& command_line);
 bool WarmUpSandbox(const base::CommandLine& command_line);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD) //XXX(rene) added !FreeBSD
 bool CollectGraphicsInfo(gpu::GPUInfo& gpu_info);
 #endif
 
@@ -192,13 +192,13 @@
   // Use a UI message loop because ANGLE and the desktop GL platform can
   // create child windows to render to.
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_UI);
-#elif defined(OS_LINUX) && defined(USE_X11)
+#elif (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_X11)
   // We need a UI loop so that we can grab the Expose events. See GLSurfaceGLX
   // and https://crbug.com/326995.
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_UI);
   std::unique_ptr<ui::PlatformEventSource> event_source =
       ui::PlatformEventSource::CreateDefault();
-#elif defined(OS_LINUX)
+#elif (defined(OS_LINUX) || defined(OS_BSD))
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_DEFAULT);
 #elif defined(OS_MACOSX)
   // This is necessary for CoreAnimation layers hosted in the GPU process to be
@@ -309,7 +309,7 @@
       // and we already registered them through SetGpuInfo() above.
       base::TimeTicks before_collect_context_graphics_info =
           base::TimeTicks::Now();
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD) //XXX(rene) added !FreeBSD
       if (!CollectGraphicsInfo(gpu_info))
         dead_on_arrival = true;
 
@@ -491,7 +491,7 @@
   return true;
 }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD)//XXX(rene) added !FreeBSD
 bool CollectGraphicsInfo(gpu::GPUInfo& gpu_info) {
   TRACE_EVENT0("gpu,startup", "Collect Graphics Info");
 

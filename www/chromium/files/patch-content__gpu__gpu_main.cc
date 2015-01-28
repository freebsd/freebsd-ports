--- content/gpu/gpu_main.cc.orig	2015-01-21 20:28:16 UTC
+++ content/gpu/gpu_main.cc
@@ -73,7 +73,7 @@
                                const CommandLine& command_line);
 bool WarmUpSandbox(const CommandLine& command_line);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD) //XXX(rene) added !FreeBSD
 bool CollectGraphicsInfo(gpu::GPUInfo& gpu_info);
 #endif
 
@@ -162,13 +162,13 @@
     message_loop_type = base::MessageLoop::TYPE_UI;
   }
   base::MessageLoop main_message_loop(message_loop_type);
-#elif defined(OS_LINUX) && defined(USE_X11)
+#elif (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
   // We need a UI loop so that we can grab the Expose events. See GLSurfaceGLX
   // and https://crbug.com/326995.
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_UI);
   scoped_ptr<ui::PlatformEventSource> event_source =
       ui::PlatformEventSource::CreateDefault();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_DEFAULT);
 #elif defined(OS_MACOSX)
   // This is necessary for CoreAnimation layers hosted in the GPU process to be
@@ -216,7 +216,7 @@
   // Temporarily disable DRI3 on desktop Linux.
   // The GPU process is crashing on DRI3-enabled desktop Linux systems.
   // TODO(jorgelo): remove this when crbug.com/415681 is fixed.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   {
     scoped_ptr<base::Environment> env(base::Environment::Create());
     env->SetVar("LIBGL_DRI3_DISABLE", "1");
@@ -279,7 +279,7 @@
       // and we already registered them through SetGpuInfo() above.
       base::TimeTicks before_collect_context_graphics_info =
           base::TimeTicks::Now();
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD) //XXX(rene) added !FreeBSD
       if (!CollectGraphicsInfo(gpu_info))
         dead_on_arrival = true;
 
@@ -412,7 +412,7 @@
   return true;
 }
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_FREEBSD)//XXX(rene) added !FreeBSD
 bool CollectGraphicsInfo(gpu::GPUInfo& gpu_info) {
   bool res = true;
   gpu::CollectInfoResult result = gpu::CollectContextGraphicsInfo(&gpu_info);

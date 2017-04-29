--- services/ui/gpu/gpu_main.cc.orig	2017-04-19 19:06:37 UTC
+++ services/ui/gpu/gpu_main.cc
@@ -59,7 +59,7 @@ GpuMain::GpuMain(mojom::GpuMainRequest r
   // runtime.
   thread_options.message_loop_type =
       ui::OzonePlatform::EnsureInstance()->GetMessageLoopTypeForGpu();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   thread_options.message_loop_type = base::MessageLoop::TYPE_DEFAULT;
 #elif defined(OS_MACOSX)
   thread_options.message_pump_factory = base::Bind(&CreateMessagePumpMac);

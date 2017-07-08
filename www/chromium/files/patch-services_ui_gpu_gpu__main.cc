--- services/ui/gpu/gpu_main.cc.orig	2017-06-05 19:03:11 UTC
+++ services/ui/gpu/gpu_main.cc
@@ -64,7 +64,7 @@ GpuMain::GpuMain(mojom::GpuMainRequest request)
   // runtime.
   thread_options.message_loop_type =
       ui::OzonePlatform::EnsureInstance()->GetMessageLoopTypeForGpu();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   thread_options.message_loop_type = base::MessageLoop::TYPE_DEFAULT;
 #elif defined(OS_MACOSX)
   thread_options.message_pump_factory = base::Bind(&CreateMessagePumpMac);

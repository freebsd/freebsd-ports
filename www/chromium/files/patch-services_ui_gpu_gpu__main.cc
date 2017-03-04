--- services/ui/gpu/gpu_main.cc.orig	2017-02-02 02:02:57 UTC
+++ services/ui/gpu/gpu_main.cc
@@ -50,7 +50,7 @@ GpuMain::GpuMain()
   thread_options.message_pump_factory = base::Bind(&CreateMessagePumpX11);
 #elif defined(USE_OZONE)
   thread_options.message_loop_type = base::MessageLoop::TYPE_UI;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   thread_options.message_loop_type = base::MessageLoop::TYPE_DEFAULT;
 #elif defined(OS_MACOSX)
   thread_options.message_pump_factory = base::Bind(&CreateMessagePumpMac);

--- services/service_manager/public/cpp/standalone_service/standalone_service.cc.orig	2017-06-05 19:03:11 UTC
+++ services/service_manager/public/cpp/standalone_service/standalone_service.cc
@@ -70,6 +70,8 @@ void RunStandaloneService(const StandaloneServiceCallb
       *base::CommandLine::ForCurrentProcess();
   if (command_line.HasSwitch(switches::kEnableSandbox))
     sandbox = InitializeSandbox();
+#elif defined(OS_BSD)
+  NOTIMPLEMENTED();
 #endif
 
   mojo::edk::Init();

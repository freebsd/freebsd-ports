--- services/service_manager/public/cpp/standalone_service/standalone_service.cc.orig	2018-02-24 16:25:18.000000000 +0100
+++ services/service_manager/public/cpp/standalone_service/standalone_service.cc	2018-03-04 03:53:12.449254000 +0100
@@ -59,6 +59,8 @@
             command_line.GetSwitchValueASCII(switches::kServiceSandboxType)),
         SandboxLinux::PreSandboxHook(), sandbox_options);
   }
+#elif defined(OS_BSD)
+  NOTIMPLEMENTED();
 #endif
 
   mojo::edk::Init();

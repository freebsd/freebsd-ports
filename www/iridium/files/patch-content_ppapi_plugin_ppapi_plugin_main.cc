--- content/ppapi_plugin/ppapi_plugin_main.cc.orig	2018-02-24 16:25:14.000000000 +0100
+++ content/ppapi_plugin/ppapi_plugin_main.cc	2018-03-04 01:29:08.347119000 +0100
@@ -125,6 +125,8 @@
       service_manager::SandboxTypeFromCommandLine(command_line),
       service_manager::SandboxLinux::PreSandboxHook(),
       service_manager::SandboxLinux::Options());
+#elif defined(OS_BSD)
+  NOTIMPLEMENTED();
 #endif
 
   ChildProcess ppapi_process;

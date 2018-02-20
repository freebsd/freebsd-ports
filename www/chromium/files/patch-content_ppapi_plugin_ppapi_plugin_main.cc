--- content/ppapi_plugin/ppapi_plugin_main.cc.orig	2018-01-20 16:16:54.514813000 +0100
+++ content/ppapi_plugin/ppapi_plugin_main.cc	2018-01-20 16:17:30.448565000 +0100
@@ -122,6 +122,8 @@
 
 #if defined(OS_LINUX)
   LinuxSandbox::InitializeSandbox();
+#elif defined(OS_BSD)
+  NOTIMPLEMENTED();
 #endif
 
   ChildProcess ppapi_process;

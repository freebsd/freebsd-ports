--- content/browser/ppapi_plugin_process_host.cc.orig	2017-07-25 21:04:55.000000000 +0200
+++ content/browser/ppapi_plugin_process_host.cc	2017-08-02 00:58:48.228556000 +0200
@@ -106,7 +106,7 @@
     return true;
   }
 
-#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();

--- content/browser/renderer_host/render_process_host_impl.cc.orig	2017-07-25 21:04:55.000000000 +0200
+++ content/browser/renderer_host/render_process_host_impl.cc	2017-08-02 01:03:34.751604000 +0200
@@ -415,7 +415,7 @@
     return GetContentClient()->browser()->PreSpawnRenderer(policy);
   }
 
-#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   ZygoteHandle GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();

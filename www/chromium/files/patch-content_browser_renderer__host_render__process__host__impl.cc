--- content/browser/renderer_host/render_process_host_impl.cc.orig	2017-12-15 02:04:17.000000000 +0100
+++ content/browser/renderer_host/render_process_host_impl.cc	2017-12-24 13:00:51.137885000 +0100
@@ -420,7 +420,7 @@
   }
 
 #elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && \
-    !defined(OS_FUCHSIA)
+    !defined(OS_FUCHSIA) && !defined(OS_BSD)
   ZygoteHandle GetZygote() override {
     const base::CommandLine& browser_command_line =
         *base::CommandLine::ForCurrentProcess();

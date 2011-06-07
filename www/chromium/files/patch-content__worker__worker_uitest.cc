--- content/worker/worker_uitest.cc.orig	2011-01-11 10:01:47.000000000 +0100
+++ content/worker/worker_uitest.cc	2011-01-15 22:46:56.000000000 +0100
@@ -85,8 +85,8 @@
     // The 1 is for the browser process.
     int number_of_processes = 1 + workers +
         (ProxyLauncher::in_process_renderer() ? 0 : tabs);
-#if defined(OS_LINUX)
-    // On Linux, we also have a zygote process and a sandbox host process.
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
+    // On Linux and FreeBSD, we also have a zygote process and a sandbox host process.
     number_of_processes += 2;
 #endif
 

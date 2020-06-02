--- third_party/blink/renderer/controller/memory_usage_monitor_posix.cc.orig	2020-05-15 15:24:43 UTC
+++ third_party/blink/renderer/controller/memory_usage_monitor_posix.cc
@@ -134,7 +134,7 @@ void MemoryUsageMonitorPosix::SetProcFiles(base::File 
   status_fd_.reset(status_file.TakePlatformFile());
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // static
 void MemoryUsageMonitorPosix::Bind(
     mojo::PendingReceiver<mojom::blink::MemoryUsageMonitorLinux> receiver) {

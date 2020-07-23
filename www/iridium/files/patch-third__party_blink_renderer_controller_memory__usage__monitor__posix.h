--- third_party/blink/renderer/controller/memory_usage_monitor_posix.h.orig	2020-03-17 10:18:29 UTC
+++ third_party/blink/renderer/controller/memory_usage_monitor_posix.h
@@ -12,7 +12,7 @@
 #include "third_party/blink/renderer/controller/controller_export.h"
 #include "third_party/blink/renderer/controller/memory_usage_monitor.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "third_party/blink/public/mojom/memory_usage_monitor_linux.mojom-blink.h"
 #endif
 
@@ -21,7 +21,7 @@ namespace blink {
 // MemoryUsageMonitor implementation for Android and Linux.
 class CONTROLLER_EXPORT MemoryUsageMonitorPosix
     : public MemoryUsageMonitor
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     ,
       public mojom::blink::MemoryUsageMonitorLinux
 #endif
@@ -29,7 +29,7 @@ class CONTROLLER_EXPORT MemoryUsageMonitorPosix
  public:
   MemoryUsageMonitorPosix() = default;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   static void Bind(
       mojo::PendingReceiver<mojom::blink::MemoryUsageMonitorLinux> receiver);
 #endif
@@ -47,7 +47,7 @@ class CONTROLLER_EXPORT MemoryUsageMonitorPosix
                                               uint64_t* vm_size,
                                               uint64_t* vm_hwm_size);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // mojom::MemoryUsageMonitorLinux implementations:
   void SetProcFiles(base::File statm_file, base::File status_file) override;
 #endif
@@ -65,7 +65,7 @@ class CONTROLLER_EXPORT MemoryUsageMonitorPosix
   base::ScopedFD statm_fd_;
   base::ScopedFD status_fd_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   mojo::Receiver<mojom::blink::MemoryUsageMonitorLinux> receiver_{this};
 #endif
 };

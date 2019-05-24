--- services/device/device_service.h.orig	2019-04-30 22:22:56 UTC
+++ services/device/device_service.h
@@ -200,7 +200,7 @@ class DeviceService : public service_manager::Service 
 #endif
 
 #if (defined(OS_LINUX) && defined(USE_UDEV)) || defined(OS_WIN) || \
-    defined(OS_MACOSX)
+    defined(OS_MACOSX) || defined(OS_BSD)
   // Requests for the SerialPortManager interface must be bound to
   // |serial_port_manager_| on |serial_port_manager_task_runner_| and it will
   // be destroyed on that sequence.

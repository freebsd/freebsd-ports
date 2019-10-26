--- src/3rdparty/chromium/services/device/device_service.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/services/device/device_service.h
@@ -198,7 +198,7 @@ class DeviceService : public service_manager::Service 
 #endif
 
 #if (defined(OS_LINUX) && defined(USE_UDEV)) || defined(OS_WIN) || \
-    defined(OS_MACOSX)
+    defined(OS_MACOSX) || defined(OS_BSD)
   // Requests for the SerialPortManager interface must be bound to
   // |serial_port_manager_| on |serial_port_manager_task_runner_| and it will
   // be destroyed on that sequence.

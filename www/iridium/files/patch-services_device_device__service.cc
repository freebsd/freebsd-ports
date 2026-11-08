--- services/device/device_service.cc.orig	2026-08-13 16:48:13 UTC
+++ services/device/device_service.cc
@@ -6,6 +6,8 @@
 
 #include <utility>
 
+#include "base/notimplemented.h"
+
 #include "base/functional/bind.h"
 #include "base/memory/weak_ptr.h"
 #include "base/task/single_thread_task_runner.h"
@@ -310,7 +312,7 @@ void DeviceService::BindSerialPortManager(
   serial_port_manager_.AsyncCall(&SerialPortManagerImpl::Bind, FROM_HERE)
       .WithArgs(std::move(receiver));
 #else   // defined(IS_SERIAL_ENABLED_PLATFORM)
-  NOTREACHED() << "Serial devices not supported on this platform.";
+  NOTIMPLEMENTED() << "Serial devices not supported on this platform.";
 #endif  // defined(IS_SERIAL_ENABLED_PLATFORM)
 }
 

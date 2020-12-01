--- content/browser/renderer_host/input/input_device_change_observer.cc.orig	2020-11-13 06:36:42 UTC
+++ content/browser/renderer_host/input/input_device_change_observer.cc
@@ -9,7 +9,7 @@
 
 #if defined(OS_WIN)
 #include "ui/events/devices/input_device_observer_win.h"
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/events/devices/device_data_manager.h"
 #elif defined(OS_ANDROID)
 #include "ui/events/devices/input_device_observer_android.h"
@@ -21,7 +21,7 @@ InputDeviceChangeObserver::InputDeviceChangeObserver(R
   render_view_host_impl_ = rvhi;
 #if defined(OS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->AddObserver(this);
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   ui::DeviceDataManager::GetInstance()->AddObserver(this);
 #elif defined(OS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->AddObserver(this);
@@ -31,7 +31,7 @@ InputDeviceChangeObserver::InputDeviceChangeObserver(R
 InputDeviceChangeObserver::~InputDeviceChangeObserver() {
 #if defined(OS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->RemoveObserver(this);
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   ui::DeviceDataManager::GetInstance()->RemoveObserver(this);
 #elif defined(OS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->RemoveObserver(this);

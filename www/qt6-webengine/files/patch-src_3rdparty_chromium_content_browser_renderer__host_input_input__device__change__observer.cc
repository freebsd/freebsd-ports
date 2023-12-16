--- src/3rdparty/chromium/content/browser/renderer_host/input/input_device_change_observer.cc.orig	2022-02-28 16:54:41 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/input/input_device_change_observer.cc
@@ -9,7 +9,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "ui/events/devices/input_device_observer_win.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/events/devices/device_data_manager.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "ui/events/devices/input_device_observer_android.h"
@@ -21,7 +21,7 @@ InputDeviceChangeObserver::InputDeviceChangeObserver(R
   render_view_host_impl_ = rvhi;
 #if BUILDFLAG(IS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->AddObserver(this);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ui::DeviceDataManager::GetInstance()->AddObserver(this);
 #elif BUILDFLAG(IS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->AddObserver(this);
@@ -31,7 +31,7 @@ InputDeviceChangeObserver::InputDeviceChangeObserver(R
 InputDeviceChangeObserver::~InputDeviceChangeObserver() {
 #if BUILDFLAG(IS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->RemoveObserver(this);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ui::DeviceDataManager::GetInstance()->RemoveObserver(this);
 #elif BUILDFLAG(IS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->RemoveObserver(this);

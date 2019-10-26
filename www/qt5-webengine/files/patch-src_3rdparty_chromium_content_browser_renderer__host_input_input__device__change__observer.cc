--- src/3rdparty/chromium/content/browser/renderer_host/input/input_device_change_observer.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/input/input_device_change_observer.cc
@@ -10,7 +10,7 @@
 
 #if defined(OS_WIN)
 #include "ui/events/devices/input_device_observer_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/events/devices/input_device_manager.h"
 #elif defined(OS_ANDROID)
 #include "ui/events/devices/input_device_observer_android.h"
@@ -22,7 +22,7 @@ InputDeviceChangeObserver::InputDeviceChangeObserver(R
   render_view_host_impl_ = rvhi;
 #if defined(OS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->AddObserver(this);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   ui::InputDeviceManager::GetInstance()->AddObserver(this);
 #elif defined(OS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->AddObserver(this);
@@ -32,7 +32,7 @@ InputDeviceChangeObserver::InputDeviceChangeObserver(R
 InputDeviceChangeObserver::~InputDeviceChangeObserver() {
 #if defined(OS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->RemoveObserver(this);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   ui::InputDeviceManager::GetInstance()->RemoveObserver(this);
 #elif defined(OS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->RemoveObserver(this);

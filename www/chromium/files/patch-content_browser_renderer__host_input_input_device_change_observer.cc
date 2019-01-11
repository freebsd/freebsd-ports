--- content/browser/renderer_host/input/input_device_change_observer.cc.orig	2019-01-09 11:52:33.084857000 +0100
+++ content/browser/renderer_host/input/input_device_change_observer.cc	2019-01-09 11:53:04.895039000 +0100
@@ -9,7 +9,7 @@
 
 #if defined(OS_WIN)
 #include "ui/events/devices/input_device_observer_win.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "ui/events/devices/input_device_manager.h"
 #elif defined(OS_ANDROID)
 #include "ui/events/devices/input_device_observer_android.h"
@@ -21,7 +21,7 @@
   render_view_host_ = rvh;
 #if defined(OS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->AddObserver(this);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   ui::InputDeviceManager::GetInstance()->AddObserver(this);
 #elif defined(OS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->AddObserver(this);
@@ -31,7 +31,7 @@
 InputDeviceChangeObserver::~InputDeviceChangeObserver() {
 #if defined(OS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->RemoveObserver(this);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   ui::InputDeviceManager::GetInstance()->RemoveObserver(this);
 #elif defined(OS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->RemoveObserver(this);

--- content/browser/web_contents/slow_web_preference_cache.cc.orig	2024-12-22 12:24:29 UTC
+++ content/browser/web_contents/slow_web_preference_cache.cc
@@ -16,7 +16,7 @@
 
 #if BUILDFLAG(IS_WIN)
 #include "ui/events/devices/input_device_observer_win.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/events/devices/device_data_manager.h"
 #elif BUILDFLAG(IS_ANDROID)
 #include "ui/base/device_form_factor.h"
@@ -54,7 +54,7 @@ SlowWebPreferenceCache::SlowWebPreferenceCache() {
 
 #if BUILDFLAG(IS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->AddObserver(this);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ui::DeviceDataManager::GetInstance()->AddObserver(this);
 #elif BUILDFLAG(IS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->AddObserver(this);
@@ -64,7 +64,7 @@ SlowWebPreferenceCache::SlowWebPreferenceCache() {
 SlowWebPreferenceCache::~SlowWebPreferenceCache() {
 #if BUILDFLAG(IS_WIN)
   ui::InputDeviceObserverWin::GetInstance()->RemoveObserver(this);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   ui::DeviceDataManager::GetInstance()->RemoveObserver(this);
 #elif BUILDFLAG(IS_ANDROID)
   ui::InputDeviceObserverAndroid::GetInstance()->RemoveObserver(this);

--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2019-09-09 21:55:46 UTC
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -826,6 +826,8 @@ void DeviceDataManagerX11::SetDisabledKeyboardAllowedK
 }
 
 void DeviceDataManagerX11::DisableDevice(int deviceid) {
+  NOTIMPLEMENTED();
+#if !defined(OS_BSD)
   blocked_devices_.set(deviceid, true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<InputDevice> keyboards = GetKeyboardDevices();
@@ -836,6 +838,7 @@ void DeviceDataManagerX11::DisableDevice(int deviceid)
     keyboards.erase(it);
     DeviceDataManager::OnKeyboardDevicesUpdated(keyboards);
   }
+#endif
 }
 
 void DeviceDataManagerX11::EnableDevice(int deviceid) {

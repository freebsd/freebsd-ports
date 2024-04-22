--- ui/events/devices/x11/device_data_manager_x11.cc.orig	2024-01-30 07:53:34 UTC
+++ ui/events/devices/x11/device_data_manager_x11.cc
@@ -844,6 +844,7 @@ void DeviceDataManagerX11::SetDisabledKeyboardAllowedK
 }
 
 void DeviceDataManagerX11::DisableDevice(x11::Input::DeviceId deviceid) {
+  NOTIMPLEMENTED();
   blocked_devices_.set(static_cast<uint32_t>(deviceid), true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<KeyboardDevice> keyboards = GetKeyboardDevices();

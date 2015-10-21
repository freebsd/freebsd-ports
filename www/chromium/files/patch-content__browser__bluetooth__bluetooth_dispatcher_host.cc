--- content/browser/bluetooth/bluetooth_dispatcher_host.cc.orig	2015-10-14 22:52:01.308600000 +0200
+++ content/browser/bluetooth/bluetooth_dispatcher_host.cc	2015-10-14 22:57:26.070951000 +0200
@@ -191,6 +191,7 @@
   set_adapter(scoped_refptr<device::BluetoothAdapter>());
 }
 
+#if 0
 // Stores information associated with an in-progress requestDevice call. This
 // will include the state of the active chooser dialog in a future patch.
 struct BluetoothDispatcherHost::RequestDeviceSession {
@@ -201,6 +202,7 @@
   std::vector<BluetoothScanFilter> filters;
   std::vector<BluetoothUUID> optional_services;
 };
+#endif
 
 void BluetoothDispatcherHost::set_adapter(
     scoped_refptr<device::BluetoothAdapter> adapter) {

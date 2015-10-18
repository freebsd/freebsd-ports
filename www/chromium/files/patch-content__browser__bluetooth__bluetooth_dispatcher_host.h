--- content/browser/bluetooth/bluetooth_dispatcher_host.h.orig	2015-10-14 22:52:05.596671000 +0200
+++ content/browser/bluetooth/bluetooth_dispatcher_host.h	2015-10-14 22:58:17.694827000 +0200
@@ -51,7 +51,14 @@
   friend class base::DeleteHelper<BluetoothDispatcherHost>;
   friend struct BrowserThread::DeleteOnThread<BrowserThread::UI>;
 
-  struct RequestDeviceSession;
+  struct RequestDeviceSession {
+    RequestDeviceSession(const std::vector<BluetoothScanFilter>& filters,
+                         const std::vector<device::BluetoothUUID>& optional_services)
+        : filters(filters), optional_services(optional_services) {}
+
+    std::vector<BluetoothScanFilter> filters;
+    std::vector<device::BluetoothUUID> optional_services;
+  };
 
   // Set |adapter_| to a BluetoothAdapter instance and register observers,
   // releasing references to previous |adapter_|.

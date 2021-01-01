--- chrome/browser/metrics/bluetooth_available_utility.cc.orig	2019-06-04 18:55:17 UTC
+++ chrome/browser/metrics/bluetooth_available_utility.cc
@@ -76,8 +76,10 @@ void ReportBluetoothAvailability() {
     return;
   }
 
+#if !defined(OS_BSD)
   device::BluetoothAdapterFactory::Get().GetAdapter(
       base::BindOnce(&OnGetAdapter));
+#endif
 }
 
 }  // namespace bluetooth_utility

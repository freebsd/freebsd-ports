--- chrome/browser/metrics/bluetooth_available_utility.cc.orig	2019-03-11 22:00:53 UTC
+++ chrome/browser/metrics/bluetooth_available_utility.cc
@@ -72,8 +72,10 @@ void ReportBluetoothAvailability() {
   if (!device::BluetoothAdapterFactory::Get().IsBluetoothSupported())
     ReportAvailability(BLUETOOTH_NOT_SUPPORTED);
 
+#if !defined(OS_BSD)
   device::BluetoothAdapterFactory::Get().GetAdapter(
       base::BindOnce(&OnGetAdapter));
+#endif
 }
 
 }  // namespace bluetooth_utility

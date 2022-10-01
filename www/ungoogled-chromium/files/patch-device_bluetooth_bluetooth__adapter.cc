--- device/bluetooth/bluetooth_adapter.cc.orig	2022-10-01 07:40:07 UTC
+++ device/bluetooth/bluetooth_adapter.cc
@@ -32,7 +32,7 @@ BluetoothAdapter::ServiceOptions::ServiceOptions() = d
 BluetoothAdapter::ServiceOptions::~ServiceOptions() = default;
 
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+    !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 // static
 scoped_refptr<BluetoothAdapter> BluetoothAdapter::CreateAdapter() {
   return nullptr;

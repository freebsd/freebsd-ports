--- src/3rdparty/chromium/device/bluetooth/bluetooth_adapter.cc.orig	2022-07-28 06:05:58 UTC
+++ src/3rdparty/chromium/device/bluetooth/bluetooth_adapter.cc
@@ -32,7 +32,7 @@ BluetoothAdapter::ServiceOptions::ServiceOptions() = d
 BluetoothAdapter::ServiceOptions::~ServiceOptions() = default;
 
 #if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_MAC) && \
-    !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
+    !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 // static
 scoped_refptr<BluetoothAdapter> BluetoothAdapter::CreateAdapter() {
   return nullptr;

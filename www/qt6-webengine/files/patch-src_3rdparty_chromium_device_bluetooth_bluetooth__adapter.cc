--- src/3rdparty/chromium/device/bluetooth/bluetooth_adapter.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/device/bluetooth/bluetooth_adapter.cc
@@ -32,7 +32,7 @@ BluetoothAdapter::ServiceOptions::~ServiceOptions() = 
 BluetoothAdapter::ServiceOptions::ServiceOptions() = default;
 BluetoothAdapter::ServiceOptions::~ServiceOptions() = default;
 
-#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS) && \
+#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD) && \
     !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_LINUX)
 // static
 scoped_refptr<BluetoothAdapter> BluetoothAdapter::CreateAdapter() {

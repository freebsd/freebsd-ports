--- src/3rdparty/chromium/components/storage_monitor/removable_device_constants.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/storage_monitor/removable_device_constants.cc
@@ -10,7 +10,7 @@ namespace storage_monitor {
 const char kFSUniqueIdPrefix[] = "UUID:";
 const char kVendorModelSerialPrefix[] = "VendorModelSerial:";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char kVendorModelVolumeStoragePrefix[] = "VendorModelVolumeStorage:";
 #endif
 

--- components/storage_monitor/removable_device_constants.cc.orig	2019-01-10 00:46:08.199066000 +0100
+++ components/storage_monitor/removable_device_constants.cc	2019-01-10 00:46:30.302527000 +0100
@@ -10,7 +10,7 @@
 const char kFSUniqueIdPrefix[] = "UUID:";
 const char kVendorModelSerialPrefix[] = "VendorModelSerial:";
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char kVendorModelVolumeStoragePrefix[] = "VendorModelVolumeStorage:";
 #endif
 

--- components/storage_monitor/removable_device_constants.h.orig	2019-01-10 00:46:17.663204000 +0100
+++ components/storage_monitor/removable_device_constants.h	2019-01-10 00:46:47.654124000 +0100
@@ -15,7 +15,7 @@
 extern const char kFSUniqueIdPrefix[];
 extern const char kVendorModelSerialPrefix[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kVendorModelVolumeStoragePrefix[];
 #endif
 

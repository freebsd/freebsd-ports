--- src/3rdparty/chromium/components/storage_monitor/removable_device_constants.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/storage_monitor/removable_device_constants.h
@@ -15,7 +15,7 @@ namespace storage_monitor {
 extern const char kFSUniqueIdPrefix[];
 extern const char kVendorModelSerialPrefix[];
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 extern const char kVendorModelVolumeStoragePrefix[];
 #endif
 

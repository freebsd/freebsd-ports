--- src/3rdparty/chromium/components/storage_monitor/removable_device_constants.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/components/storage_monitor/removable_device_constants.h
@@ -14,7 +14,7 @@ extern const char kVendorModelSerialPrefix[];
 extern const char kFSUniqueIdPrefix[];
 extern const char kVendorModelSerialPrefix[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kVendorModelVolumeStoragePrefix[];
 #endif
 

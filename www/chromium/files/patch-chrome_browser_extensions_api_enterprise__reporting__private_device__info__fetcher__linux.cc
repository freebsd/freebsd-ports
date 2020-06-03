--- chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc.orig	2020-05-13 18:39:37 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc
@@ -8,7 +8,9 @@
 #include <gio/gio.h>
 #endif  // defined(USE_GIO)
 #include <sys/stat.h>
+#if !defined(OS_BSD)
 #include <sys/sysmacros.h>
+#endif
 
 #include <string>
 
@@ -91,6 +93,7 @@ enterprise_reporting_private::SettingValue GetScreenlo
 // Implements the logic from the native host installation script. First find the
 // root device identifier, then locate its parent and get its type.
 enterprise_reporting_private::SettingValue GetDiskEncrypted() {
+#if !defined(OS_BSD)
   struct stat info;
   // First figure out the device identifier.
   stat("/", &info);
@@ -110,6 +113,7 @@ enterprise_reporting_private::SettingValue GetDiskEncr
     return is_encrypted ? enterprise_reporting_private::SETTING_VALUE_ENABLED
                         : enterprise_reporting_private::SETTING_VALUE_DISABLED;
   }
+#endif
   return enterprise_reporting_private::SETTING_VALUE_UNKNOWN;
 }
 
@@ -121,7 +125,11 @@ DeviceInfoFetcherLinux::~DeviceInfoFetcherLinux() = de
 
 DeviceInfo DeviceInfoFetcherLinux::Fetch() {
   DeviceInfo device_info;
+#if defined(OS_FREEBSD)
+  device_info.os_name = "freebsd";
+#else
   device_info.os_name = "linux";
+#endif
   device_info.os_version = GetOsVersion();
   device_info.device_host_name = GetDeviceHostName();
   device_info.device_model = GetDeviceModel();

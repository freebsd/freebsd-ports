--- chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc.orig	2020-03-18 08:39:42 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc
@@ -8,7 +8,9 @@
 #include <gio/gio.h>
 #endif  // defined(USE_GIO)
 #include <sys/stat.h>
+#if !defined(OS_BSD)
 #include <sys/sysmacros.h>
+#endif
 
 #include <string>
 
@@ -90,6 +92,7 @@ enterprise_reporting_private::SettingValue GetScreenlo
 // Implements the logic from the native host installation script. First find the
 // root device identifier, then locate its parent and get its type.
 enterprise_reporting_private::SettingValue GetDiskEncrypted() {
+#if !defined(OS_BSD)
   struct stat info;
   // First figure out the device identifier.
   stat("/", &info);
@@ -109,6 +112,7 @@ enterprise_reporting_private::SettingValue GetDiskEncr
     return is_encrypted ? enterprise_reporting_private::SETTING_VALUE_ENABLED
                         : enterprise_reporting_private::SETTING_VALUE_DISABLED;
   }
+#endif
   return enterprise_reporting_private::SETTING_VALUE_UNKNOWN;
 }
 
@@ -120,7 +124,11 @@ DeviceInfoFetcherLinux::~DeviceInfoFetcherLinux() = de
 
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

--- chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc.orig	2020-11-13 06:36:36 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/device_info_fetcher_linux.cc
@@ -8,7 +8,9 @@
 #include <gio/gio.h>
 #endif  // defined(USE_GIO)
 #include <sys/stat.h>
+#if !defined(OS_BSD)
 #include <sys/sysmacros.h>
+#endif
 
 #include <string>
 
@@ -36,7 +38,11 @@ std::string GetDeviceModel() {
 }
 
 std::string GetOsVersion() {
+#if defined(OS_BSD)
+  base::FilePath os_release_file("/usr/local/etc/os-release");
+#else
   base::FilePath os_release_file("/etc/os-release");
+#endif
   std::string release_info;
   base::StringPairs values;
   if (base::PathExists(os_release_file) &&
@@ -107,6 +113,7 @@ enterprise_reporting_private::SettingValue GetScreenlo
 // Implements the logic from the native host installation script. First find the
 // root device identifier, then locate its parent and get its type.
 enterprise_reporting_private::SettingValue GetDiskEncrypted() {
+#if !defined(OS_BSD)
   struct stat info;
   // First figure out the device identifier. Fail fast if this fails.
   if (stat("/", &info) != 0)
@@ -131,10 +138,14 @@ enterprise_reporting_private::SettingValue GetDiskEncr
     return enterprise_reporting_private::SETTING_VALUE_UNKNOWN;
   }
   return enterprise_reporting_private::SETTING_VALUE_DISABLED;
+#else
+  return enterprise_reporting_private::SETTING_VALUE_UNKNOWN;
+#endif
 }
 
 std::vector<std::string> GetMacAddresses() {
   std::vector<std::string> result;
+#if !defined(OS_BSD)
   base::DirReaderPosix reader("/sys/class/net");
   if (!reader.IsValid())
     return result;
@@ -157,6 +168,7 @@ std::vector<std::string> GetMacAddresses() {
                               &address);
     result.push_back(address);
   }
+#endif
   return result;
 }
 
@@ -168,7 +180,11 @@ DeviceInfoFetcherLinux::~DeviceInfoFetcherLinux() = de
 
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

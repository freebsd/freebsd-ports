--- components/sync_device_info/local_device_info_util.cc.orig	2026-05-09 18:09:27 UTC
+++ components/sync_device_info/local_device_info_util.cc
@@ -84,7 +84,7 @@ void OnMachineStatisticsLoaded(LocalDeviceNameInfo* na
 DeviceInfo::DeviceType GetLocalDeviceType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return DeviceInfo::DeviceType::kChromeOS;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::DeviceType::kLinux;
 #elif BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
   switch (ui::GetDeviceFormFactor()) {
@@ -107,7 +107,7 @@ DeviceInfo::DeviceType GetLocalDeviceType() {
 DeviceInfo::OsType GetLocalDeviceOSType() {
 #if BUILDFLAG(IS_CHROMEOS)
   return DeviceInfo::OsType::kChromeOsAsh;
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return DeviceInfo::OsType::kLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return DeviceInfo::OsType::kAndroid;

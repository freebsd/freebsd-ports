--- components/sync_device_info/local_device_info_util_linux.cc.orig	2020-02-24 18:39:14 UTC
+++ components/sync_device_info/local_device_info_util_linux.cc
@@ -37,8 +37,9 @@ std::string GetPersonalizableDeviceNameInternal() {
 #if defined(OS_CHROMEOS)
   return GetChromeOSDeviceNameFromType();
 #else
-  char hostname[HOST_NAME_MAX];
-  if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
+  int len = sysconf(_SC_HOST_NAME_MAX);
+  char hostname[len];
+  if (gethostname(hostname, _SC_HOST_NAME_MAX) == 0)  // Success.
     return hostname;
   return base::GetLinuxDistro();
 #endif

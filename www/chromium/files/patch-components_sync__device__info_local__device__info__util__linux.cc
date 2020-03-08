--- components/sync_device_info/local_device_info_util_linux.cc.orig	2020-03-03 18:53:06 UTC
+++ components/sync_device_info/local_device_info_util_linux.cc
@@ -8,6 +8,7 @@
 #include <string>
 
 #include "base/linux_util.h"
+#include "build/build_config.h"
 
 #if defined(OS_CHROMEOS)
 #include "chromeos/constants/devicetype.h"
@@ -36,6 +37,23 @@ std::string GetChromeOSDeviceNameFromType() {
 std::string GetPersonalizableDeviceNameInternal() {
 #if defined(OS_CHROMEOS)
   return GetChromeOSDeviceNameFromType();
+#elif defined(OS_BSD)
+  long len = sysconf(_SC_HOST_NAME_MAX);
+
+  if (len == -1)
+    return "FreeBSD";
+
+  char *hostname = new (std::nothrow) char[len]();
+
+  if ((hostname == nullptr) || (gethostname(hostname, len) == -1)) {
+    delete[](hostname);
+    return "FreeBSD";
+  }
+
+  std::string res{hostname};
+  delete[](hostname);
+
+  return res;
 #else
   char hostname[HOST_NAME_MAX];
   if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.

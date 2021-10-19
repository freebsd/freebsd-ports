--- chrome/updater/device_management/cloud_policy_util.cc.orig	2021-09-24 18:39:26 UTC
+++ chrome/updater/device_management/cloud_policy_util.cc
@@ -21,7 +21,7 @@
 #include <wincred.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -35,7 +35,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <limits.h>  // For HOST_NAME_MAX
 #endif
 
@@ -62,7 +62,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/system/sys_info.h"
 #endif
 
@@ -115,6 +115,11 @@ std::string GetMachineName() {
   if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
     return hostname;
   return std::string();
+#elif defined(OS_BSD)
+  char hostname[MAXHOSTNAMELEN];
+  if (gethostname(hostname, MAXHOSTNAMELEN) == 0)  // Success.
+    return hostname;
+  return std::string();
 #elif defined(OS_MAC)
   // Do not use NSHost currentHost, as it's very slow. http://crbug.com/138570
   SCDynamicStoreContext context = {0, NULL, NULL, NULL};
@@ -160,7 +165,7 @@ std::string GetMachineName() {
 }
 
 std::string GetOSVersion() {
-#if defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
   return base::SysInfo::OperatingSystemVersion();
 #elif defined(OS_WIN)
   base::win::OSInfo::VersionNumber version_number =

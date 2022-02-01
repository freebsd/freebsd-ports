--- chrome/updater/device_management/cloud_policy_util.cc.orig	2021-12-14 11:45:01 UTC
+++ chrome/updater/device_management/cloud_policy_util.cc
@@ -22,7 +22,7 @@
 #include <wincred.h>
 #endif
 
-#if defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -36,7 +36,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include <limits.h>  // For HOST_NAME_MAX
 #endif
 
@@ -63,7 +63,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #include "base/system/sys_info.h"
 #endif
 
@@ -116,6 +116,11 @@ std::string GetMachineName() {
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
@@ -161,7 +166,7 @@ std::string GetMachineName() {
 }
 
 std::string GetOSVersion() {
-#if defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
   return base::SysInfo::OperatingSystemVersion();
 #elif defined(OS_WIN)
   base::win::OSInfo::VersionNumber version_number =

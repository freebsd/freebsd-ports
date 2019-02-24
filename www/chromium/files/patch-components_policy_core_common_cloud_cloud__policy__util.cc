--- components/policy/core/common/cloud/cloud_policy_util.cc.orig	2019-02-06 22:50:06.437715000 +0100
+++ components/policy/core/common/cloud/cloud_policy_util.cc	2019-02-07 01:42:29.673954000 +0100
@@ -16,7 +16,7 @@
 #include <wincred.h>
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -28,7 +28,7 @@
 #include <sys/sysctl.h>
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include <limits.h>  // For HOST_NAME_MAX
 #endif
 
@@ -51,7 +51,7 @@
 #include "base/system/sys_info.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
 #include "base/system/sys_info.h"
 #endif
 
@@ -60,11 +60,24 @@
 namespace em = enterprise_management;
 
 std::string GetMachineName() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
   char hostname[HOST_NAME_MAX];
   if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
     return hostname;
   return std::string();
+#elif defined(OS_BSD)
+  long host_name_max = sysconf(_SC_HOST_NAME_MAX);
+  if (host_name_max != -1) {
+    char *hostname = new char[host_name_max + 1]();
+    std::string hostname_r;
+
+    if (gethostname(hostname, host_name_max) == 0)
+      hostname_r = hostname;
+
+    delete[] hostname;
+    return hostname_r;
+  }
+  return std::string();
 #elif defined(OS_MACOSX)
   // Do not use NSHost currentHost, as it's very slow. http://crbug.com/138570
   SCDynamicStoreContext context = {0, NULL, NULL, NULL};
@@ -110,7 +123,7 @@
 }
 
 std::string GetOSVersion() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
   return base::SysInfo::OperatingSystemVersion();
 #elif defined(OS_WIN)
   base::win::OSInfo::VersionNumber version_number =
@@ -133,7 +146,7 @@
 }
 
 std::string GetOSUsername() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) || defined(OS_MACOSX)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
   struct passwd* creds = getpwuid(getuid());
   if (!creds || !creds->pw_name)
     return std::string();

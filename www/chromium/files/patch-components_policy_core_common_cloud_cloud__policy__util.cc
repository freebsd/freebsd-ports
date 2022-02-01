--- components/policy/core/common/cloud/cloud_policy_util.cc.orig	2021-12-31 00:57:30 UTC
+++ components/policy/core/common/cloud/cloud_policy_util.cc
@@ -18,7 +18,7 @@
 #include <wincred.h>
 #endif
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE) || defined(OS_BSD)
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -33,7 +33,7 @@
 #import <SystemConfiguration/SCDynamicStoreCopySpecific.h>
 #endif
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include <limits.h>  // For HOST_NAME_MAX
 #endif
 
@@ -67,7 +67,7 @@
 #include "base/system/sys_info.h"
 #endif
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "base/system/sys_info.h"
 #endif
 
@@ -85,6 +85,10 @@ std::string GetMachineName() {
   if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
     return hostname;
   return std::string();
+#elif defined(OS_BSD)
+  char hostname[MAXHOSTNAMELEN];
+  if (gethostname(hostname, MAXHOSTNAMELEN) == 0)
+    return hostname;
 #elif defined(OS_IOS)
   // Use the Vendor ID as the machine name.
   return ios::device_util::GetVendorId();
@@ -137,7 +141,7 @@ std::string GetMachineName() {
 }
 
 std::string GetOSVersion() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_APPLE) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_APPLE) || defined(OS_BSD) || \
     defined(OS_ANDROID) || defined(OS_FUCHSIA)
   return base::SysInfo::OperatingSystemVersion();
 #elif defined(OS_WIN)
@@ -161,7 +165,7 @@ std::string GetOSArchitecture() {
 }
 
 std::string GetOSUsername() {
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE) || defined(OS_BSD)
   struct passwd* creds = getpwuid(getuid());
   if (!creds || !creds->pw_name)
     return std::string();

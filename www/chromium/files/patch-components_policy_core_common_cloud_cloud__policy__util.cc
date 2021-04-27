--- components/policy/core/common/cloud/cloud_policy_util.cc.orig	2021-04-14 18:41:00 UTC
+++ components/policy/core/common/cloud/cloud_policy_util.cc
@@ -18,7 +18,7 @@
 #include <wincred.h>
 #endif
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE) || defined(OS_BSD)
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -35,7 +35,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include <limits.h>  // For HOST_NAME_MAX
 #endif
 
@@ -71,7 +71,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "base/system/sys_info.h"
 #endif
 
@@ -108,6 +108,10 @@ std::string GetMachineName() {
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
@@ -156,7 +160,7 @@ std::string GetMachineName() {
 }
 
 std::string GetOSVersion() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_APPLE)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_APPLE) || defined(OS_BSD)
   return base::SysInfo::OperatingSystemVersion();
 #elif defined(OS_WIN)
   base::win::OSInfo::VersionNumber version_number =
@@ -179,7 +183,7 @@ std::string GetOSArchitecture() {
 }
 
 std::string GetOSUsername() {
-#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_APPLE)
+#if (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_APPLE) || defined(OS_BSD)
   struct passwd* creds = getpwuid(getuid());
   if (!creds || !creds->pw_name)
     return std::string();

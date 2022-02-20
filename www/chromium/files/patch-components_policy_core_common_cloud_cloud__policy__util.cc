--- components/policy/core/common/cloud/cloud_policy_util.cc.orig	2022-02-07 13:39:41 UTC
+++ components/policy/core/common/cloud/cloud_policy_util.cc
@@ -18,7 +18,7 @@
 #include <wincred.h>
 #endif
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE) || defined(OS_BSD)
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -33,10 +33,14 @@
 #import <SystemConfiguration/SCDynamicStoreCopySpecific.h>
 #endif
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include <limits.h>  // For HOST_NAME_MAX
 #endif
 
+#if defined(OS_FREEBSD)
+#define HOST_NAME_MAX MAXHOSTNAMELEN
+#endif
+
 #include <utility>
 
 #include "base/check.h"
@@ -67,7 +71,7 @@
 #include "base/system/sys_info.h"
 #endif
 
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "base/system/sys_info.h"
 #endif
 
@@ -80,7 +84,7 @@ namespace policy {
 namespace em = enterprise_management;
 
 std::string GetMachineName() {
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   char hostname[HOST_NAME_MAX];
   if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
     return hostname;
@@ -138,7 +142,7 @@ std::string GetMachineName() {
 
 std::string GetOSVersion() {
 #if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_APPLE) || \
-    defined(OS_ANDROID) || defined(OS_FUCHSIA)
+    defined(OS_ANDROID) || defined(OS_FUCHSIA) || defined(OS_BSD)
   return base::SysInfo::OperatingSystemVersion();
 #elif defined(OS_WIN)
   base::win::OSInfo::VersionNumber version_number =
@@ -161,7 +165,7 @@ std::string GetOSArchitecture() {
 }
 
 std::string GetOSUsername() {
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_APPLE) || defined(OS_BSD)
   struct passwd* creds = getpwuid(getuid());
   if (!creds || !creds->pw_name)
     return std::string();

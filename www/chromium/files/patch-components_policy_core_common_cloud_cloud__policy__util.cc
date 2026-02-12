--- components/policy/core/common/cloud/cloud_policy_util.cc.orig	2026-02-11 09:05:39 UTC
+++ components/policy/core/common/cloud/cloud_policy_util.cc
@@ -23,7 +23,7 @@
 #include "base/win/wincred_shim.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include <pwd.h>
 #include <sys/types.h>
 #include <unistd.h>
@@ -38,10 +38,15 @@
 #import <SystemConfiguration/SCDynamicStoreCopySpecific.h>
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include <limits.h>  // For HOST_NAME_MAX
 #endif
 
+#if BUILDFLAG(IS_FREEBSD)
+#include <sys/param.h>
+#define HOST_NAME_MAX MAXHOSTNAMELEN
+#endif
+
 #include <algorithm>
 #include <utility>
 
@@ -92,7 +97,7 @@ const int kMinimumVersionForExtensionInstallPolicy = 1
 }  // namespace
 
 std::string GetMachineName() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   char hostname[HOST_NAME_MAX];
   if (gethostname(hostname, HOST_NAME_MAX) == 0)  // Success.
     return hostname;
@@ -148,7 +153,7 @@ std::string GetMachineName() {
 
 std::string GetOSVersion() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_APPLE) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   return base::SysInfo::OperatingSystemVersion();
 #elif BUILDFLAG(IS_WIN)
   base::win::OSInfo::VersionNumber version_number =
@@ -170,7 +175,7 @@ std::string GetOSArchitecture() {
 }
 
 std::string GetOSUsername() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_BSD)
   struct passwd* creds = getpwuid(getuid());
   if (!creds || !creds->pw_name)
     return std::string();

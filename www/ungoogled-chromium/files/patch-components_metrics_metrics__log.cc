--- components/metrics/metrics_log.cc.orig	2025-02-20 09:59:21 UTC
+++ components/metrics/metrics_log.cc
@@ -60,7 +60,7 @@
 #include "base/win/current_module.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -150,7 +150,7 @@ void RecordCurrentTime(
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 metrics::SystemProfileProto::OS::XdgSessionType ToProtoSessionType(
     base::nix::SessionType session_type) {
   switch (session_type) {
@@ -413,7 +413,7 @@ void MetricsLog::RecordCoreSystemProfile(
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if BUILDFLAG(IS_CHROMEOS)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());
@@ -430,7 +430,7 @@ void MetricsLog::RecordCoreSystemProfile(
   os->set_build_number(base::SysInfo::GetIOSBuildNumber());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env = base::Environment::Create();
   os->set_xdg_session_type(ToProtoSessionType(base::nix::GetSessionType(*env)));
   os->set_xdg_current_desktop(

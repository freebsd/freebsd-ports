--- components/metrics/metrics_log.cc.orig	2025-03-05 08:14:56 UTC
+++ components/metrics/metrics_log.cc
@@ -61,7 +61,7 @@
 #include "base/win/current_module.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -157,7 +157,7 @@ void RecordCurrentTime(
   }
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 metrics::SystemProfileProto::OS::XdgSessionType ToProtoSessionType(
     base::nix::SessionType session_type) {
   switch (session_type) {
@@ -435,7 +435,7 @@ void MetricsLog::RecordCoreSystemProfile(
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if BUILDFLAG(IS_CHROMEOS)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());
@@ -452,7 +452,7 @@ void MetricsLog::RecordCoreSystemProfile(
   os->set_build_number(base::SysInfo::GetIOSBuildNumber());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env = base::Environment::Create();
   os->set_xdg_session_type(ToProtoSessionType(base::nix::GetSessionType(*env)));
   os->set_xdg_current_desktop(

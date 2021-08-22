--- components/metrics/metrics_log.cc.orig	2021-07-19 18:45:13 UTC
+++ components/metrics/metrics_log.cc
@@ -249,7 +249,7 @@ void MetricsLog::RecordCoreSystemProfile(
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if BUILDFLAG(IS_CHROMEOS_ASH)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());

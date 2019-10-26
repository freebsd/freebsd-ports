--- src/3rdparty/chromium/components/metrics/metrics_log.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/components/metrics/metrics_log.cc
@@ -198,7 +198,7 @@ void MetricsLog::RecordCoreSystemProfile(MetricsServic
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if defined(OS_CHROMEOS)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());

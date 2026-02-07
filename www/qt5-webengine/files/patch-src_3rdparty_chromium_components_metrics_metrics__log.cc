--- src/3rdparty/chromium/components/metrics/metrics_log.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/components/metrics/metrics_log.cc
@@ -224,7 +224,7 @@ void MetricsLog::RecordCoreSystemProfile(
 // OperatingSystemVersion refers to the ChromeOS release version.
 #if defined(OS_CHROMEOS)
   os->set_kernel_version(base::SysInfo::KernelVersion());
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   // Linux operating system version is copied over into kernel version to be
   // consistent.
   os->set_kernel_version(base::SysInfo::OperatingSystemVersion());

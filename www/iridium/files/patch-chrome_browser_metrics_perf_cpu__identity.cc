--- chrome/browser/metrics/perf/cpu_identity.cc.orig	2024-06-25 12:08:48 UTC
+++ chrome/browser/metrics/perf/cpu_identity.cc
@@ -142,7 +142,7 @@ CPUIdentity GetCPUIdentity() {
   result.release =
 #if BUILDFLAG(IS_CHROMEOS_ASH)
       base::SysInfo::KernelVersion();
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
       base::SysInfo::OperatingSystemVersion();
 #else
 #error "Unsupported configuration"

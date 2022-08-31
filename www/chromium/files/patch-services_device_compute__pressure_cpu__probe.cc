--- services/device/compute_pressure/cpu_probe.cc.orig	2022-08-31 12:19:35 UTC
+++ services/device/compute_pressure/cpu_probe.cc
@@ -55,6 +55,7 @@ std::unique_ptr<CpuProbe> CpuProbe::Create() {
 #elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
   return CpuProbeLinux::Create();
 #else
+  NOTIMPLEMENTED();
   return std::make_unique<NullCpuProbe>();
 #endif  // BUILDFLAG(IS_ANDROID)
 }

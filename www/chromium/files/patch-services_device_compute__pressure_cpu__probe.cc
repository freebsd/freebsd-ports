--- services/device/compute_pressure/cpu_probe.cc.orig	2024-01-30 07:53:34 UTC
+++ services/device/compute_pressure/cpu_probe.cc
@@ -60,6 +60,7 @@ std::unique_ptr<CpuProbe> CpuProbe::Create(
 #elif BUILDFLAG(IS_MAC)
   return CpuProbeMac::Create(sampling_interval, std::move(sampling_callback));
 #else
+  NOTIMPLEMENTED();
   return nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }

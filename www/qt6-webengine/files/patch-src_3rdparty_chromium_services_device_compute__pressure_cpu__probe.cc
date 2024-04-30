--- src/3rdparty/chromium/services/device/compute_pressure/cpu_probe.cc.orig	2023-04-28 17:01:32 UTC
+++ src/3rdparty/chromium/services/device/compute_pressure/cpu_probe.cc
@@ -44,6 +44,7 @@ std::unique_ptr<CpuProbe> CpuProbe::Create(
 #elif BUILDFLAG(IS_MAC)
   return CpuProbeMac::Create(sampling_interval, std::move(sampling_callback));
 #else
+  NOTIMPLEMENTED();
   return nullptr;
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 }

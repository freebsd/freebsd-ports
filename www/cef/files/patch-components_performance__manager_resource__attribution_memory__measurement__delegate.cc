--- components/performance_manager/resource_attribution/memory_measurement_delegate.cc.orig	2026-02-11 09:05:39 UTC
+++ components/performance_manager/resource_attribution/memory_measurement_delegate.cc
@@ -100,7 +100,7 @@ void MemoryMeasurementDelegateImpl::OnMemorySummary(
                 base::KiBU(process_dump.os_dump().resident_set_kb),
             .private_footprint =
                 base::KiBU(process_dump.os_dump().private_footprint_kb),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
             // `private_footprint_swap_kb` is only defined on these platforms
             .private_swap =
                 base::KiBU(process_dump.os_dump().private_footprint_swap_kb),

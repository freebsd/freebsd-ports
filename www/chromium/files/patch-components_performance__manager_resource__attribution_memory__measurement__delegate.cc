--- components/performance_manager/resource_attribution/memory_measurement_delegate.cc.orig	2025-10-30 15:44:36 UTC
+++ components/performance_manager/resource_attribution/memory_measurement_delegate.cc
@@ -100,7 +100,7 @@ void MemoryMeasurementDelegateImpl::OnMemorySummary(
                 base::KiB(process_dump.os_dump().resident_set_kb),
             .private_footprint =
                 base::KiB(process_dump.os_dump().private_footprint_kb),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
             // `private_footprint_swap_kb` is only defined on these platforms
             .private_swap =
                 base::KiB(process_dump.os_dump().private_footprint_swap_kb),

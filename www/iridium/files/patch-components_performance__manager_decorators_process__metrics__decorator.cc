--- components/performance_manager/decorators/process_metrics_decorator.cc.orig	2025-10-28 14:29:43 UTC
+++ components/performance_manager/decorators/process_metrics_decorator.cc
@@ -266,7 +266,7 @@ void ProcessMetricsDecorator::DidGetMemoryUsage(
     base::ByteCount process_rss =
         base::KiB(process_dump_iter.os_dump().resident_set_kb);
     process_node->set_resident_set(process_rss);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     process_node->set_private_swap(
         base::KiB(process_dump_iter.os_dump().private_footprint_swap_kb));
 #endif

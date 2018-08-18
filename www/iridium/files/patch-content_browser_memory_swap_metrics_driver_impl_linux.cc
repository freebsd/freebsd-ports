--- content/browser/memory/swap_metrics_driver_impl_linux.cc.orig	2018-06-13 00:10:16.000000000 +0200
+++ content/browser/memory/swap_metrics_driver_impl_linux.cc	2018-07-21 00:28:47.747286000 +0200
@@ -44,9 +44,13 @@
 SwapMetricsDriver::SwapMetricsUpdateResult
 SwapMetricsDriverImplLinux::UpdateMetricsInternal(base::TimeDelta interval) {
   base::VmStatInfo vmstat;
+#if !defined(OS_BSD)
   if (!base::GetVmStatInfo(&vmstat)) {
     return SwapMetricsDriver::SwapMetricsUpdateResult::kSwapMetricsUpdateFailed;
   }
+#else
+    return SwapMetricsDriver::SwapMetricsUpdateResult::kSwapMetricsUpdateFailed;
+#endif
 
   uint64_t in_counts = vmstat.pswpin - last_pswpin_;
   uint64_t out_counts = vmstat.pswpout - last_pswpout_;

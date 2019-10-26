--- src/3rdparty/chromium/content/browser/memory/swap_metrics_driver_impl_linux.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/content/browser/memory/swap_metrics_driver_impl_linux.cc
@@ -43,6 +43,7 @@ SwapMetricsDriverImplLinux::~SwapMetricsDriverImplLinu
 
 SwapMetricsDriver::SwapMetricsUpdateResult
 SwapMetricsDriverImplLinux::UpdateMetricsInternal(base::TimeDelta interval) {
+#if !defined(OS_BSD)
   base::VmStatInfo vmstat;
   if (!base::GetVmStatInfo(&vmstat)) {
     return SwapMetricsDriver::SwapMetricsUpdateResult::kSwapMetricsUpdateFailed;
@@ -55,12 +56,15 @@ SwapMetricsDriverImplLinux::UpdateMetricsInternal(base
 
   if (interval.is_zero())
     return SwapMetricsDriver::SwapMetricsUpdateResult::
-        kSwapMetricsUpdateSuccess;
+    kSwapMetricsUpdateSuccess;
 
   delegate_->OnSwapInCount(in_counts, interval);
   delegate_->OnSwapOutCount(out_counts, interval);
 
   return SwapMetricsDriver::SwapMetricsUpdateResult::kSwapMetricsUpdateSuccess;
+#else
+  return SwapMetricsDriver::SwapMetricsUpdateResult::kSwapMetricsUpdateFailed;
+#endif
 }
 
 }  // namespace content

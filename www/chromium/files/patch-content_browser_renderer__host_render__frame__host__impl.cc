--- content/browser/renderer_host/render_frame_host_impl.cc.orig	2023-09-13 12:11:42 UTC
+++ content/browser/renderer_host/render_frame_host_impl.cc
@@ -8509,7 +8509,11 @@ void RenderFrameHostImpl::SendFencedFrameReportingBeac
   for (const blink::FencedFrame::ReportingDestination& destination :
        destinations) {
     SendFencedFrameReportingBeaconInternal(
+#if defined(__clang__) && (__clang_major__ >= 16)
         DestinationEnumEvent(event_type, event_data), destination,
+#else
+        DestinationEnumEvent(DestinationEnumEvent{event_type, event_data}), destination,
+#endif
         /*from_renderer=*/true, attribution_reporting_runtime_features,
         GetFrameTreeNodeId());
   }
@@ -8545,7 +8549,11 @@ void RenderFrameHostImpl::SendFencedFrameReportingBeac
   }
 
   SendFencedFrameReportingBeaconInternal(
+#if defined(__clang__) && (__clang_major__ >= 16)
       DestinationURLEvent(destination_url),
+#else
+      DestinationURLEvent(DestinationURLEvent{destination_url}),
+#endif
       blink::FencedFrame::ReportingDestination::kBuyer,
       /*from_renderer=*/true, attribution_reporting_runtime_features,
       GetFrameTreeNodeId());
@@ -8617,8 +8625,13 @@ void RenderFrameHostImpl::MaybeSendFencedFrameReportin
   for (blink::FencedFrame::ReportingDestination destination :
        info->destinations) {
     initiator_rfh->SendFencedFrameReportingBeaconInternal(
+#if defined(__clang__) && (__clang_major__ >= 16)
         DestinationEnumEvent(blink::kFencedFrameTopNavigationBeaconType,
                              info->data),
+#else
+        DestinationEnumEvent(DestinationEnumEvent{blink::kFencedFrameTopNavigationBeaconType,
+                             info->data}),
+#endif
         destination,
         /*from_renderer=*/false, info->attribution_reporting_runtime_features,
         GetFrameTreeNodeId(), navigation_request.GetNavigationId());

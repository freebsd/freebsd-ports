--- content/browser/renderer_host/render_frame_host_impl.cc.orig	2023-10-11 18:22:24 UTC
+++ content/browser/renderer_host/render_frame_host_impl.cc
@@ -8672,7 +8672,11 @@ void RenderFrameHostImpl::SendFencedFrameReportingBeac
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
@@ -8708,7 +8712,11 @@ void RenderFrameHostImpl::SendFencedFrameReportingBeac
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
@@ -8779,8 +8787,13 @@ void RenderFrameHostImpl::MaybeSendFencedFrameReportin
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

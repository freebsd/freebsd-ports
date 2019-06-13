--- cc/scheduler/compositor_frame_reporting_controller.cc.orig	2019-06-04 18:55:15 UTC
+++ cc/scheduler/compositor_frame_reporting_controller.cc
@@ -31,8 +31,6 @@ void CompositorFrameReportingController::WillBeginImpl
 
 void CompositorFrameReportingController::WillBeginMainFrame() {
   DCHECK(reporters_[PipelineStage::kBeginImplFrame]);
-  DCHECK_NE(reporters_[PipelineStage::kBeginMainFrame],
-            reporters_[PipelineStage::kBeginImplFrame]);
   reporters_[PipelineStage::kBeginImplFrame]->StartStage(
       "SendBeginMainFrameToCommit");
   AdvanceReporterStage(PipelineStage::kBeginImplFrame,

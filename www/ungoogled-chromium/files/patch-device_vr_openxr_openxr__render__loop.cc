--- device/vr/openxr/openxr_render_loop.cc.orig	2026-11-17 11:49:09 UTC
+++ device/vr/openxr/openxr_render_loop.cc
@@ -982,7 +982,7 @@ void OpenXrRenderLoop::SubmitFrameDrawnIntoTexture(
 
   // No GPU fence: a CPU finish guarantees the WebGL write completed before the
   // binding reads the shared image. WaitOnFence is a no-op without a fence FD.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40286368): wait through ClientSharedImage once it can wait
   // on the sync tokens without the finish.
   for (const auto& sync_token : combined_sync_tokens) {
@@ -1006,7 +1006,7 @@ void OpenXrRenderLoop::SubmitFrameDrawnIntoTexture(
 #endif
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void OpenXrRenderLoop::OnWebXrWritesFlushed(
     int16_t frame_index,
     std::vector<LayerId> updated_layers) {

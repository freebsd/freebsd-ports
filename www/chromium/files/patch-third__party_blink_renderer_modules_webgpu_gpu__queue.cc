--- third_party/blink/renderer/modules/webgpu/gpu_queue.cc.orig	2023-04-28 17:01:32 UTC
+++ third_party/blink/renderer/modules/webgpu/gpu_queue.cc
@@ -676,7 +676,7 @@ bool GPUQueue::CopyFromCanvasSourceImage(
 // on linux platform.
 // TODO(crbug.com/1424119): using a webgpu mailbox texture on the OpenGLES
 // backend is failing for unknown reasons.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool forceReadback = true;
 #else
   bool forceReadback =

--- third_party/blink/renderer/modules/webgpu/gpu_queue.cc.orig	2023-08-17 07:33:31 UTC
+++ third_party/blink/renderer/modules/webgpu/gpu_queue.cc
@@ -694,7 +694,7 @@ bool GPUQueue::CopyFromCanvasSourceImage(
 // on linux platform.
 // TODO(crbug.com/1424119): using a webgpu mailbox texture on the OpenGLES
 // backend is failing for unknown reasons.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool forceReadback = true;
 #elif BUILDFLAG(IS_WIN)
   bool forceReadback =

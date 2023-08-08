--- third_party/blink/renderer/modules/webgpu/gpu_queue.cc.orig	2023-06-05 19:39:05 UTC
+++ third_party/blink/renderer/modules/webgpu/gpu_queue.cc
@@ -679,7 +679,7 @@ bool GPUQueue::CopyFromCanvasSourceImage(
 // platform requires interop supported. According to the bug, this change will
 // be a long time task. So disable using webgpu mailbox texture uploading path
 // on linux platform.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   use_webgpu_mailbox_texture = false;
   unaccelerated_image = image->MakeUnaccelerated();
   image = unaccelerated_image.get();

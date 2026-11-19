--- third_party/blink/renderer/modules/webgpu/external_image_utils.cc.orig	2026-11-19 12:25:27 UTC
+++ third_party/blink/renderer/modules/webgpu/external_image_utils.cc
@@ -424,7 +424,7 @@ bool CopyStaticImageBitmapToWGPUTexture(
 // on linux platform.
 // TODO(crbug.com/1424119): using a webgpu mailbox texture on the OpenGLES
 // backend is failing for unknown reasons.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool forceReadback = true;
 #elif BUILDFLAG(IS_ANDROID)
   // TODO(crbug.com/dawn/1969): Some Android devices don't fail to copy from

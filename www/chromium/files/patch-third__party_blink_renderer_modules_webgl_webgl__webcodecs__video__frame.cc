--- third_party/blink/renderer/modules/webgl/webgl_webcodecs_video_frame.cc.orig	2021-09-14 01:52:03 UTC
+++ third_party/blink/renderer/modules/webgl/webgl_webcodecs_video_frame.cc
@@ -98,7 +98,7 @@ WebGLExtensionName WebGLWebCodecsVideoFrame::GetName()
 bool WebGLWebCodecsVideoFrame::Supported(WebGLRenderingContextBase* context) {
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(jie.a.chen@intel.com): Add Linux support.
   return false;
 #elif defined(OS_MAC)

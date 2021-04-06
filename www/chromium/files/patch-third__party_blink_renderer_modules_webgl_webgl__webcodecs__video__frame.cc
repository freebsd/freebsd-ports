--- third_party/blink/renderer/modules/webgl/webgl_webcodecs_video_frame.cc.orig	2021-03-12 23:57:30 UTC
+++ third_party/blink/renderer/modules/webgl/webgl_webcodecs_video_frame.cc
@@ -235,7 +235,7 @@ WebGLExtensionName WebGLWebCodecsVideoFrame::GetName()
 }
 
 bool WebGLWebCodecsVideoFrame::Supported(WebGLRenderingContextBase* context) {
-#if defined(OS_LINUX) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_FUCHSIA) || defined(OS_BSD)
   // TODO(jie.a.chen@intel.com): Add Linux support.
   return false;
 #else

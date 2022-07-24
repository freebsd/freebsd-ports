--- third_party/blink/renderer/modules/webgl/webgl_webcodecs_video_frame.cc.orig	2022-07-22 17:30:31 UTC
+++ third_party/blink/renderer/modules/webgl/webgl_webcodecs_video_frame.cc
@@ -101,7 +101,7 @@ bool WebGLWebCodecsVideoFrame::Supported(WebGLRenderin
 // TODO(crbug.com/1052397): Revisit once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   // TODO(jie.a.chen@intel.com): Add Linux support.
   return false;
 #elif BUILDFLAG(IS_MAC)

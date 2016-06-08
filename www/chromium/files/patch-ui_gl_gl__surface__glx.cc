--- ui/gl/gl_surface_glx.cc.orig	2016-05-11 19:02:35 UTC
+++ ui/gl/gl_surface_glx.cc
@@ -48,7 +48,7 @@ bool g_glx_get_msc_rate_oml_supported = 
 bool g_glx_sgi_video_sync_supported = false;
 
 static const int kGetVSyncParametersMinSeconds =
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // See crbug.com/373489
     // On Linux, querying the vsync parameters might burn CPU for up to an
     // entire vsync, so we only query periodically to reduce CPU usage.

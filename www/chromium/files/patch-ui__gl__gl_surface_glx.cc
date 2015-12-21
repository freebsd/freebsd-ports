--- ui/gl/gl_surface_glx.cc.orig	2015-10-14 19:05:53.638848000 +0200
+++ ui/gl/gl_surface_glx.cc	2015-10-14 19:06:56.014680000 +0200
@@ -48,7 +48,7 @@
 bool g_glx_sgi_video_sync_supported = false;
 
 static const int kGetVSyncParametersMinSeconds =
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // See crbug.com/373489
     // On Linux, querying the vsync parameters might burn CPU for up to an
     // entire vsync, so we only query periodically to reduce CPU usage.

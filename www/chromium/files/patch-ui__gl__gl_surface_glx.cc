--- ui/gl/gl_surface_glx.cc.orig	2015-10-06 22:42:29.000000000 -0400
+++ ui/gl/gl_surface_glx.cc	2015-10-14 12:11:35.193730000 -0400
@@ -48,7 +48,7 @@
 bool g_glx_sgi_video_sync_supported = false;
 
 static const int kGetVSyncParametersMinSeconds =
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // See crbug.com/373489
     // On Linux, querying the vsync parameters might burn CPU for up to an
     // entire vsync, so we only query periodically to reduce CPU usage.

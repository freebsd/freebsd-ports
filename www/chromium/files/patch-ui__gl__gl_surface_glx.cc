--- ui/gl/gl_surface_glx.cc.orig	2015-04-14 18:31:23.000000000 -0400
+++ ui/gl/gl_surface_glx.cc	2015-04-28 08:44:08.840888000 -0400
@@ -57,7 +57,7 @@
 bool g_glx_sgi_video_sync_supported = false;
 
 static const base::TimeDelta kGetVSyncParametersMinPeriod =
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // See crbug.com/373489
     // On Linux, querying the vsync parameters might burn CPU for up to an
     // entire vsync, so we only query periodically to reduce CPU usage.

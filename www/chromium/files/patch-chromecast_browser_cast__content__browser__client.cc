--- chromecast/browser/cast_content_browser_client.cc.orig	2018-06-13 00:10:12.000000000 +0200
+++ chromecast/browser/cast_content_browser_client.cc	2018-07-18 23:13:48.741141000 +0200
@@ -416,7 +416,7 @@
                                           switches::kAudioOutputChannels));
     }
   } else if (process_type == switches::kGpuProcess) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Necessary for accelerated 2d canvas.  By default on Linux, Chromium assumes
   // GLES2 contexts can be lost to a power-save mode, which breaks GPU canvas
   // apps.

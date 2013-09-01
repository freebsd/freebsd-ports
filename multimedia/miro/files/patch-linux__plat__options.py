--- ./linux/plat/options.py.orig	2013-08-17 02:50:01.620777937 +0000
+++ ./linux/plat/options.py	2013-08-17 02:50:48.339773948 +0000
@@ -51,7 +51,7 @@
 
 FFMPEG_BINARY = LinuxPref(
     key="ffmpegBinary",
-    default="/usr/bin/ffmpeg",
+    default="%%LOCALBASE%%/bin/ffmpeg",
     alias="ffmpeg",
     helptext="Absolute path for ffmpeg binary.")
 

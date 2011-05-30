--- ./linux/plat/options.py.orig	2011-05-25 17:56:13.000000000 +0200
+++ ./linux/plat/options.py	2011-05-25 17:56:57.000000000 +0200
@@ -51,13 +51,13 @@
 
 FFMPEG_BINARY = LinuxPref(
     key="ffmpegBinary",
-    default="/usr/bin/ffmpeg",
+    default="%%LOCALBASE%%/bin/ffmpeg",
     alias="ffmpeg",
     helptext="Absolute path for ffmpeg binary.")
 
 FFMPEG2THEORA_BINARY = LinuxPref(
     key="ffmpeg2TheoraBinary",
-    default="/usr/bin/ffmpeg2theora",
+    default="%%LOCALBASE%%/bin/ffmpeg2theora",
     alias="ffmpeg2theora",
     helptext="Absolute path for ffmpeg2theora binary.")
 

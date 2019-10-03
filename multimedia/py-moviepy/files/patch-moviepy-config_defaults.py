--- moviepy/config_defaults.py.orig	2019-10-01 15:30:18 UTC
+++ moviepy/config_defaults.py
@@ -50,5 +50,6 @@ IMAGEMAGICK_BINARY
 
 import os
 
-FFMPEG_BINARY = os.getenv('FFMPEG_BINARY', 'ffmpeg-imageio')
+# Use ffmpeg from ports
+FFMPEG_BINARY = "ffmpeg"
 IMAGEMAGICK_BINARY = os.getenv('IMAGEMAGICK_BINARY', 'auto-detect')

--- moviepy/config_defaults.py.orig	2018-12-15 16:06:35 UTC
+++ moviepy/config_defaults.py
@@ -50,5 +50,6 @@ IMAGEMAGICK_BINARY
 
 import os
 
-FFMPEG_BINARY = os.getenv('FFMPEG_BINARY', 'ffmpeg-imageio')
-IMAGEMAGICK_BINARY = os.getenv('IMAGEMAGICK_BINARY', 'auto-detect')
\ No newline at end of file
+# Use ffmpeg from ports
+FFMPEG_BINARY = "ffmpeg"
+IMAGEMAGICK_BINARY = os.getenv('IMAGEMAGICK_BINARY', 'auto-detect')

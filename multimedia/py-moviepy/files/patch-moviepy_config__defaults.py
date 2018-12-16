--- moviepy/config_defaults.py.orig	2018-12-16 18:28:09 UTC
+++ moviepy/config_defaults.py
@@ -50,5 +50,6 @@ IMAGEMAGICK_BINARY
 
 import os
 
-FFMPEG_BINARY = os.getenv('FFMPEG_BINARY', 'ffmpeg-imageio')
-IMAGEMAGICK_BINARY = os.getenv('IMAGEMAGICK_BINARY', 'auto-detect')
\ No newline at end of file
+FFMPEG_BINARY = "ffmpeg"  # by default it asks py-imageio to download ffmpeg from GitHub, but it doesn't exist there for FreeBSD, and it is also an insecure download
+                          # instead, just default to "ffmpeg" which means to use the local binary
+IMAGEMAGICK_BINARY = os.getenv('IMAGEMAGICK_BINARY', 'auto-detect')

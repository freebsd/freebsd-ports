--- moviepy/editor.py.orig	2018-12-16 18:36:01 UTC
+++ moviepy/editor.py
@@ -21,8 +21,10 @@ import os
 
 # Downloads ffmpeg if it isn't already installed
 import imageio
+from moviepy.config import get_setting
+
 # Checks to see if the user has set a place for their own version of ffmpeg
-if os.getenv('FFMPEG_BINARY', 'ffmpeg-imageio') == 'ffmpeg-imageio':
+if get_setting("FFMPEG_BINARY") == 'ffmpeg-imageio':
     imageio.plugins.ffmpeg.download()
 
 # Clips

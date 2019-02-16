--- moviepy/editor.py.orig	2019-02-14 01:02:48 UTC
+++ moviepy/editor.py
@@ -20,15 +20,6 @@ clip.preview().
 import os
 import sys
 
-# Downloads ffmpeg if it isn't already installed
-import imageio
-# Checks to see if the user has set a place for their own version of ffmpeg
-
-if os.getenv('FFMPEG_BINARY', 'ffmpeg-imageio') == 'ffmpeg-imageio':
-    if sys.version_info < (3, 4):
-        #uses an old version of imageio with ffmpeg.download.
-        imageio.plugins.ffmpeg.download()
-
 # Clips
 from .video.io.VideoFileClip import VideoFileClip
 from .video.io.ImageSequenceClip import ImageSequenceClip

--- moviepy/editor.py.orig	2020-03-24 20:20:06 UTC
+++ moviepy/editor.py
@@ -20,18 +20,6 @@ clip.preview().
 import os
 import sys
 
-# Downloads ffmpeg if it isn't already installed
-import imageio
-# Checks to see if the user has set a place for their own version of ffmpeg
-
-if os.getenv('FFMPEG_BINARY') is None:
-    if sys.version_info < (3, 4):
-        #uses an old version of imageio with ffmpeg.download.
-        imageio.plugins.ffmpeg.download()
-
-# Hide the welcome message from pygame: https://github.com/pygame/pygame/issues/542
-os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "1"
-
 # Clips
 from .video.io.VideoFileClip import VideoFileClip
 from .video.io.ImageSequenceClip import ImageSequenceClip

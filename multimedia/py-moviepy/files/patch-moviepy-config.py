--- moviepy/config.py.orig	2024-11-20 05:20:50 UTC
+++ moviepy/config.py
@@ -15,7 +15,7 @@ except ImportError:
 except ImportError:
     DOTENV = None
 
-FFMPEG_BINARY = os.getenv("FFMPEG_BINARY", "ffmpeg-imageio")
+FFMPEG_BINARY = os.getenv("FFMPEG_BINARY", "ffmpeg")
 FFPLAY_BINARY = os.getenv("FFPLAY_BINARY", "auto-detect")
 
 IS_POSIX_OS = os.name == "posix"

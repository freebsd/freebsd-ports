--- firedm/video.py.orig	2022-02-05 14:10:51 UTC
+++ firedm/video.py
@@ -733,6 +733,9 @@ def load_extractor_engines(reload=False):
 
         load_user_extractors(engine=yt_dlp)
 
+    # XXX: assume we always have youtube-dl -> yt-dlp symlink
+    import sys
+    sys.path.append('/usr/local/bin/youtube-dl')
     run_thread(import_youtube_dl, daemon=True)
     run_thread(import_yt_dlp, daemon=True)
 

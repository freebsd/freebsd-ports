--- pafy/backend_youtube_dl.py.orig	2019-11-20 14:42:31 UTC
+++ pafy/backend_youtube_dl.py
@@ -10,7 +10,10 @@ if sys.version_info[:2] >= (3, 0):
 else:
     uni = unicode
 
-import youtube_dl
+if sys.platform.startswith('freebsd'):
+    # FreeBSD installs youtube_dl as a zip archive
+    sys.path.insert(1, '%%LOCALBASE%%/bin/youtube-dl')
+import yt_dlp
 
 from . import g
 from .backend_shared import BasePafy, BaseStream, remux, get_status_string, get_size_done

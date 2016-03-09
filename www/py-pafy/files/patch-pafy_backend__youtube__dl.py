--- pafy/backend_youtube_dl.py.orig	2016-03-05 21:47:16 UTC
+++ pafy/backend_youtube_dl.py
@@ -8,6 +8,9 @@ if sys.version_info[:2] >= (3, 0):
 else:
     uni = unicode
 
+if sys.platform.startswith('freebsd'):
+    # FreeBSD installs youtube_dl as a zip archive
+    sys.path.insert(1, '%%LOCALBASE%%/bin/youtube-dl')
 import youtube_dl
 
 from . import g

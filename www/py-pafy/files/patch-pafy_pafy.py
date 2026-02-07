--- pafy/pafy.py.orig	2019-11-20 14:42:31 UTC
+++ pafy/pafy.py
@@ -45,7 +45,10 @@ Pafy = None
 backend = "internal"
 if os.environ.get("PAFY_BACKEND") != "internal":
     try:
-        import youtube_dl
+        if sys.platform.startswith('freebsd'):
+            # FreeBSD installs youtube_dl as a zip archive
+            sys.path.insert(1, '%%LOCALBASE%%/bin/youtube-dl')
+        import yt_dlp
         backend = "youtube-dl"
     except ImportError:
         raise ImportError(

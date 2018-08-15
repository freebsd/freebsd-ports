--- pafy/pafy.py.orig	2018-02-11 21:15:57 UTC
+++ pafy/pafy.py
@@ -45,6 +45,9 @@ Pafy = None
 backend = "internal"
 if os.environ.get("PAFY_BACKEND") != "internal":
     try:
+        if sys.platform.startswith('freebsd'):
+            # FreeBSD installs youtube_dl as a zip archive
+            sys.path.insert(1, '%%LOCALBASE%%/bin/youtube-dl')
         import youtube_dl
         backend = "youtube-dl"
     except ImportError:

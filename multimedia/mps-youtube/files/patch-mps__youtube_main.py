--- mps_youtube/main.py.orig	2015-01-25 16:46:50 UTC
+++ mps_youtube/main.py
@@ -856,6 +856,10 @@ def init():
     init_cache()
     init_transcode()
 
+    # see https://github.com/np1/mps-youtube/issues/179
+    if 34015728 <= sys.hexversion and not 'SSL_CERT_FILE' in os.environ:
+        os.environ['SSL_CERT_FILE'] = '%%LOCALBASE%%/share/certs/ca-root-nss.crt'
+
     # set player to mpv or mplayer if found, otherwise unset
     E = os.path.exists
     suffix = ".exe" if mswin else ""

--- yt_dlp/cookies.py.orig	2022-05-14 11:34:22.365323000 -0400
+++ yt_dlp/cookies.py	2022-05-14 11:34:52.544340000 -0400
@@ -140,7 +140,7 @@
 
 
 def _firefox_browser_dir():
-    if sys.platform in ('linux', 'linux2'):
+    if sys.platform in ('linux', 'linux2','freebsd13','freebsd14'):
         return os.path.expanduser('~/.mozilla/firefox')
     elif sys.platform == 'win32':
         return os.path.expandvars(r'%APPDATA%\Mozilla\Firefox\Profiles')

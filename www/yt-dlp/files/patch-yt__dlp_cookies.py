--- yt_dlp/cookies.py.orig	2022-05-18 03:37:32 UTC
+++ yt_dlp/cookies.py
@@ -156,7 +156,7 @@ def _extract_firefox_cookies(profile, logger):
 
 
 def _firefox_browser_dir():
-    if sys.platform in ('linux', 'linux2'):
+    if sys.platform in ('linux', 'linux2','freebsd13','freebsd14'):
         return os.path.expanduser('~/.mozilla/firefox')
     elif sys.platform == 'win32':
         return os.path.expandvars(R'%APPDATA%\Mozilla\Firefox\Profiles')

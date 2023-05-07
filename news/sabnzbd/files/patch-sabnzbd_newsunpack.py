--- sabnzbd/newsunpack.py.orig	2022-01-28 10:50:34 UTC
+++ sabnzbd/newsunpack.py
@@ -136,6 +136,8 @@ def find_programs(curdir: str):
         if not sabnzbd.newsunpack.SEVENZIP_COMMAND:
             sabnzbd.newsunpack.SEVENZIP_COMMAND = find_on_path("7za")  # 7za = 7z stand-alone executable
         if not sabnzbd.newsunpack.SEVENZIP_COMMAND:
+            sabnzbd.newsunpack.SEVENZIP_COMMAND = find_on_path("7zz")
+        if not sabnzbd.newsunpack.SEVENZIP_COMMAND:
             sabnzbd.newsunpack.SEVENZIP_COMMAND = find_on_path("7z")
 
     if not (sabnzbd.WIN32 or sabnzbd.DARWIN):

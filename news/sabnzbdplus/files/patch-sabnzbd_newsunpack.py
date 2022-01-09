--- sabnzbd/newsunpack.py.orig	2021-10-15 06:30:37 UTC
+++ sabnzbd/newsunpack.py
@@ -127,6 +127,8 @@ def find_programs(curdir):
         if not sabnzbd.newsunpack.SEVEN_COMMAND:
             sabnzbd.newsunpack.SEVEN_COMMAND = find_on_path("7za")
         if not sabnzbd.newsunpack.SEVEN_COMMAND:
+            sabnzbd.newsunpack.SEVEN_COMMAND = find_on_path("7zz")
+        if not sabnzbd.newsunpack.SEVEN_COMMAND:
             sabnzbd.newsunpack.SEVEN_COMMAND = find_on_path("7z")
 
     if not (sabnzbd.WIN32 or sabnzbd.DARWIN):

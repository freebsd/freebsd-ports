--- yt_dlp/options.py.orig	2022-06-22 01:17:57 UTC
+++ yt_dlp/options.py
@@ -313,10 +313,6 @@ def create_parser():
         action='version',
         help='Print program version and exit')
     general.add_option(
-        '-U', '--update',
-        action='store_true', dest='update_self',
-        help='Update this program to latest version')
-    general.add_option(
         '--no-update',
         action='store_false', dest='update_self',
         help='Do not update (default)')

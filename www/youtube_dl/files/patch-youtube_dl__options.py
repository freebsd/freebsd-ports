--- youtube_dl/options.py.orig	2014-11-15 22:16:23.000000000 +0800
+++ youtube_dl/options.py	2014-11-22 12:34:15.188052389 +0800
@@ -125,10 +125,6 @@
         action='version',
         help='print program version and exit')
     general.add_option(
-        '-U', '--update',
-        action='store_true', dest='update_self',
-        help='update this program to latest version. Make sure that you have sufficient permissions (run with sudo if needed)')
-    general.add_option(
         '-i', '--ignore-errors',
         action='store_true', dest='ignoreerrors', default=False,
         help='continue on download errors, for example to skip unavailable videos in a playlist')

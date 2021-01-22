--- youtube_dlc/options.py.orig	2021-01-17 22:30:37 UTC
+++ youtube_dlc/options.py
@@ -131,10 +131,6 @@ def parseOpts(overrideArguments=None):
         action='version',
         help='Print program version and exit')
     general.add_option(
-        '-U', '--update',
-        action='store_true', dest='update_self',
-        help='[BROKEN] Update this program to latest version. Make sure that you have sufficient permissions (run with sudo if needed)')
-    general.add_option(
         '-i', '--ignore-errors', '--no-abort-on-error',
         action='store_true', dest='ignoreerrors', default=True,
         help='Continue on download errors, for example to skip unavailable videos in a playlist (default)')

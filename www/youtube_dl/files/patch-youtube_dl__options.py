--- youtube_dl/options.py.orig	2016-04-28 23:04:36 UTC
+++ youtube_dl/options.py
@@ -127,10 +127,6 @@ def parseOpts(overrideArguments=None):
         action='version',
         help='Print program version and exit')
     general.add_option(
-        '-U', '--update',
-        action='store_true', dest='update_self',
-        help='Update this program to latest version. Make sure that you have sufficient permissions (run with sudo if needed)')
-    general.add_option(
         '-i', '--ignore-errors',
         action='store_true', dest='ignoreerrors', default=False,
         help='Continue on download errors, for example to skip unavailable videos in a playlist')

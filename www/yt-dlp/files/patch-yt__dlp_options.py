--- yt_dlp/options.py.orig	2021-10-22 20:47:18 UTC
+++ yt_dlp/options.py
@@ -203,10 +203,6 @@ def parseOpts(overrideArguments=None):
         action='version',
         help='Print program version and exit')
     general.add_option(
-        '-U', '--update',
-        action='store_true', dest='update_self',
-        help='Update this program to latest version. Make sure that you have sufficient permissions (run with sudo if needed)')
-    general.add_option(
         '-i', '--ignore-errors',
         action='store_true', dest='ignoreerrors',
         help='Ignore download and postprocessing errors. The download will be considered successfull even if the postprocessing fails')

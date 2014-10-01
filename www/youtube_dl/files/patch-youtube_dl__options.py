--- youtube_dl/options.py.orig	2014-10-01 13:10:09 UTC
+++ youtube_dl/options.py
@@ -127,8 +127,6 @@
             action='help', help='print this help text and exit')
     general.add_option('-v', '--version',
             action='version', help='print program version and exit')
-    general.add_option('-U', '--update',
-            action='store_true', dest='update_self', help='update this program to latest version. Make sure that you have sufficient permissions (run with sudo if needed)')
     general.add_option('-i', '--ignore-errors',
             action='store_true', dest='ignoreerrors', help='continue on download errors, for example to skip unavailable videos in a playlist', default=False)
     general.add_option('--abort-on-error',

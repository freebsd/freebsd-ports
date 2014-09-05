--- youtube_dl/__init__.py.orig	2014-07-29 23:18:51.000000000 +0800
+++ youtube_dl/__init__.py	2014-07-31 01:10:45.923443081 +0800
@@ -97,7 +97,6 @@
     std_headers,
     write_string,
 )
-from .update import update_self
 from .downloader import (
     FileDownloader,
 )
@@ -230,8 +229,6 @@
             action='help', help='print this help text and exit')
     general.add_option('-v', '--version',
             action='version', help='print program version and exit')
-    general.add_option('-U', '--update',
-            action='store_true', dest='update_self', help='update this program to latest version. Make sure that you have sufficient permissions (run with sudo if needed)')
     general.add_option('-i', '--ignore-errors',
             action='store_true', dest='ignoreerrors', help='continue on download errors, for example to skip unavailable videos in a playlist', default=False)
     general.add_option('--abort-on-error',
@@ -844,10 +841,6 @@
                 ydl.add_post_processor(FFmpegAudioFixPP())
             ydl.add_post_processor(AtomicParsleyPP())
 
-        # Update version
-        if opts.update_self:
-            update_self(ydl.to_screen, opts.verbose)
-
         # Remove cache dir
         if opts.rm_cachedir:
             if opts.cachedir is None:
@@ -867,7 +860,7 @@
 
         # Maybe do nothing
         if (len(all_urls) < 1) and (opts.load_info_filename is None):
-            if not (opts.update_self or opts.rm_cachedir):
+            if not (opts.rm_cachedir):
                 parser.error(u'you must provide at least one URL')
             else:
                 sys.exit()

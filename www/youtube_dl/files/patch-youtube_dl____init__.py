--- ./youtube_dl/__init__.py.orig	2014-02-25 09:29:35.000000000 +0000
+++ ./youtube_dl/__init__.py	2014-02-25 09:29:49.000000000 +0000
@@ -76,7 +76,6 @@
     std_headers,
     write_string,
 )
-from .update import update_self
 from .FileDownloader import (
     FileDownloader,
 )
@@ -206,8 +205,6 @@
             action='help', help='print this help text and exit')
     general.add_option('-v', '--version',
             action='version', help='print program version and exit')
-    general.add_option('-U', '--update',
-            action='store_true', dest='update_self', help='update this program to latest version. Make sure that you have sufficient permissions (run with sudo if needed)')
     general.add_option('-i', '--ignore-errors',
             action='store_true', dest='ignoreerrors', help='continue on download errors, for example to skip unavailable videos in a playlist', default=False)
     general.add_option('--abort-on-error',
@@ -777,17 +774,6 @@
         if opts.xattrs:
             ydl.add_post_processor(XAttrMetadataPP())
 
-        # Update version
-        if opts.update_self:
-            update_self(ydl.to_screen, opts.verbose)
-
-        # Maybe do nothing
-        if (len(all_urls) < 1) and (opts.load_info_filename is None):
-            if not opts.update_self:
-                parser.error(u'you must provide at least one URL')
-            else:
-                sys.exit()
-
         try:
             if opts.load_info_filename is not None:
                 retcode = ydl.download_with_info_file(opts.load_info_filename)

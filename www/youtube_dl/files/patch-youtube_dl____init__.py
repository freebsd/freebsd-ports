--- youtube_dl/__init__.py.orig	2014-09-27 21:51:19 UTC
+++ youtube_dl/__init__.py
@@ -108,7 +108,6 @@
     std_headers,
     write_string,
 )
-from .update import update_self
 from .downloader import (
     FileDownloader,
 )
@@ -399,17 +398,13 @@
             ydl.add_post_processor(ExecAfterDownloadPP(
                 verboseOutput=opts.verbose, exec_cmd=opts.exec_cmd))
 
-        # Update version
-        if opts.update_self:
-            update_self(ydl.to_screen, opts.verbose)
-
         # Remove cache dir
         if opts.rm_cachedir:
             ydl.cache.remove()
 
         # Maybe do nothing
         if (len(all_urls) < 1) and (opts.load_info_filename is None):
-            if not (opts.update_self or opts.rm_cachedir):
+            if not (opts.rm_cachedir):
                 parser.error(u'you must provide at least one URL')
             else:
                 sys.exit()

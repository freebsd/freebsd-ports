--- youtube_dl/__init__.py.orig	2014-11-23 17:50:21.000000000 +0800
+++ youtube_dl/__init__.py	2014-11-23 21:17:37.918929006 +0800
@@ -34,7 +34,6 @@
     std_headers,
     write_string,
 )
-from .update import update_self
 from .downloader import (
     FileDownloader,
 )
@@ -347,17 +346,13 @@ def _real_main(argv=None):
     }
 
     with YoutubeDL(ydl_opts) as ydl:
-        # Update version
-        if opts.update_self:
-            update_self(ydl.to_screen, opts.verbose)
-
         # Remove cache dir
         if opts.rm_cachedir:
             ydl.cache.remove()
 
         # Maybe do nothing
         if (len(all_urls) < 1) and (opts.load_info_filename is None):
-            if opts.update_self or opts.rm_cachedir:
+            if opts.rm_cachedir:
                 sys.exit()
 
             ydl.warn_if_short_id(sys.argv[1:] if argv is None else argv)

--- youtube_dlc/__init__.py.orig	2021-01-16 18:54:52 UTC
+++ youtube_dlc/__init__.py
@@ -39,7 +39,6 @@ from .utils import (
     write_string,
     render_table,
 )
-from .update import update_self
 from .downloader import (
     FileDownloader,
 )
@@ -499,17 +498,13 @@ def _real_main(argv=None):
     }
 
     with YoutubeDL(ydl_opts) as ydl:
-        # Update version
-        if opts.update_self:
-            update_self(ydl.to_screen, opts.verbose, ydl._opener)
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

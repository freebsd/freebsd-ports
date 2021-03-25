--- yt_dlp/__init__.py.orig	2021-03-18 03:08:48 UTC
+++ yt_dlp/__init__.py
@@ -38,7 +38,6 @@ from .utils import (
     std_headers,
     write_string,
 )
-from .update import update_self
 from .downloader import (
     FileDownloader,
 )
@@ -580,17 +579,9 @@ def _real_main(argv=None):
         if opts.rm_cachedir:
             ydl.cache.remove()
 
-        # Update version
-        if opts.update_self:
-            # If updater returns True, exit. Required for windows
-            if update_self(ydl.to_screen, opts.verbose, ydl._opener):
-                if actual_use:
-                    sys.exit('ERROR: The program must exit for the update to complete')
-                sys.exit()
-
         # Maybe do nothing
         if not actual_use:
-            if opts.update_self or opts.rm_cachedir:
+            if opts.rm_cachedir:
                 sys.exit()
 
             ydl.warn_if_short_id(sys.argv[1:] if argv is None else argv)

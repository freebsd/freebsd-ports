--- youtube_dlc/__init__.py.orig	2021-02-19 21:44:01 UTC
+++ youtube_dlc/__init__.py
@@ -38,7 +38,6 @@ from .utils import (
     std_headers,
     write_string,
 )
-from .update import update_self
 from .downloader import (
     FileDownloader,
 )
@@ -556,17 +555,9 @@ def _real_main(argv=None):
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

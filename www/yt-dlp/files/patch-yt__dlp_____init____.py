--- yt_dlp/__init__.py.orig	2021-06-01 14:59:03 UTC
+++ yt_dlp/__init__.py
@@ -660,17 +660,9 @@ def _real_main(argv=None):
         if opts.rm_cachedir:
             ydl.cache.remove()
 
-        # Update version
-        if opts.update_self:
-            # If updater returns True, exit. Required for windows
-            if run_update(ydl):
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

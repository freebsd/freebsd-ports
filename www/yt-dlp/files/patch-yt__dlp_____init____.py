--- yt_dlp/__init__.py.orig	2022-06-22 00:50:42 UTC
+++ yt_dlp/__init__.py
@@ -879,20 +879,20 @@ def _real_main(argv=None):
         return
 
     with YoutubeDL(ydl_opts) as ydl:
-        pre_process = opts.update_self or opts.rm_cachedir
+        pre_process = opts.rm_cachedir
         actual_use = all_urls or opts.load_info_filename
 
         if opts.rm_cachedir:
             ydl.cache.remove()
 
-        updater = Updater(ydl)
-        if opts.update_self and updater.update() and actual_use:
-            if updater.cmd:
-                return updater.restart()
-            # This code is reachable only for zip variant in py < 3.10
-            # It makes sense to exit here, but the old behavior is to continue
-            ydl.report_warning('Restart yt-dlp to use the updated version')
-            # return 100, 'ERROR: The program must exit for the update to complete'
+        #updater = Updater(ydl)
+        #if opts.update_self and updater.update() and actual_use:
+        #    if updater.cmd:
+        #        return updater.restart()
+        #    # This code is reachable only for zip variant in py < 3.10
+        #    # It makes sense to exit here, but the old behavior is to continue
+        #    ydl.report_warning('Restart yt-dlp to use the updated version')
+        #    # return 100, 'ERROR: The program must exit for the update to complete'
 
         if not actual_use:
             if pre_process:

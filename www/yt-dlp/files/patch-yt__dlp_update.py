- this patch prevents -U from updating yt-dlp - it makes it "unrecognized"

--- yt_dlp/update.py.orig	2022-06-22 01:54:04 UTC
+++ yt_dlp/update.py
@@ -29,7 +29,7 @@ def _get_variant_and_executable_path():
 
     path = os.path.dirname(__file__)
     if isinstance(__loader__, zipimporter):
-        return 'zip', os.path.join(path, '..')
+        return 'unknown', os.path.join(path, '..')
     elif (os.path.basename(sys.argv[0]) in ('__main__.py', '-m')
           and os.path.exists(os.path.join(path, '../.git/HEAD'))):
         return 'source', path

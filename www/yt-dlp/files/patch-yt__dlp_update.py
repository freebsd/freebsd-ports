- this patch prevents -U from updating yt-dlp - it makes it "unrecognized"

--- yt_dlp/update.py.orig	2025-11-12 00:51:24 UTC
+++ yt_dlp/update.py
@@ -105,7 +105,7 @@ def _get_variant_and_executable_path():
 
     path = os.path.dirname(__file__)
     if isinstance(__loader__, zipimporter):
-        return 'zip', os.path.join(path, '..')
+        return 'unknown', os.path.join(path, '..')
     elif (os.path.basename(sys.argv[0]) in ('__main__.py', '-m')
           and os.path.exists(os.path.join(path, '../.git/HEAD'))):
         return 'source', path
@@ -148,7 +148,7 @@ _NON_UPDATEABLE_REASONS = {
         'Auto-update is not supported for unpackaged executables; Re-download the latest release'),
     'py2exe': 'py2exe is no longer supported by yt-dlp; This executable cannot be updated',
     'source': 'You cannot update when running from source code; Use git to pull the latest changes',
-    'unknown': 'You installed yt-dlp from a manual build or with a package manager; Use that to update',
+    'unknown': 'Please use the command \'pkg upgrade yt-dlp\' to upgrade.',
     'other': 'You are using an unofficial build of yt-dlp; Build the executable again',
 }
 

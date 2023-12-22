- this patch prevents -U from updating yt-dlp - it makes it "unrecognized"

--- yt_dlp/update.py.orig	2023-11-16 00:02:06 UTC
+++ yt_dlp/update.py
@@ -73,7 +73,7 @@ def _get_variant_and_executable_path():
 
     path = os.path.dirname(__file__)
     if isinstance(__loader__, zipimporter):
-        return 'zip', os.path.join(path, '..')
+        return 'unknown', os.path.join(path, '..')
     elif (os.path.basename(sys.argv[0]) in ('__main__.py', '-m')
           and os.path.exists(os.path.join(path, '../.git/HEAD'))):
         return 'source', path
@@ -114,7 +114,7 @@ _NON_UPDATEABLE_REASONS = {
     **{variant: f'Auto-update is not supported for unpackaged {name} executable; Re-download the latest release'
        for variant, name in {'win32_dir': 'Windows', 'darwin_dir': 'MacOS', 'linux_dir': 'Linux'}.items()},
     'source': 'You cannot update when running from source code; Use git to pull the latest changes',
-    'unknown': 'You installed yt-dlp with a package manager or setup.py; Use that to update',
+    'unknown': 'Please use the command \'pkg upgrade yt-dlp\' to upgrade.',
     'other': 'You are using an unofficial build of yt-dlp; Build the executable again',
 }
 

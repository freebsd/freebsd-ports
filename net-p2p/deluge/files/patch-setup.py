--- setup.py.orig	2016-07-20 14:23:28 UTC
+++ setup.py
@@ -215,6 +215,7 @@ except ImportError:
     build_libtorrent = True
 else:
     build_libtorrent = False
+build_libtorrent = False
 
 if build_libtorrent:
     got_libtorrent = False
@@ -515,6 +516,7 @@ if not windows_check() and not osx_check
 
     if os.path.exists(desktop_data):
         _data_files.append(('share/applications', [desktop_data]))
+    _data_files = []
 
 entry_points = {
     "console_scripts": [

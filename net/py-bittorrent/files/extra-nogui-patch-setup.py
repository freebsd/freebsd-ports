--- setup.py.orig	Sat Mar 12 10:01:45 2005
+++ setup.py	Sat Mar 12 10:14:21 2005
@@ -19,7 +19,7 @@
 
 import glob
 
-scripts = ["btdownloadgui.py", "btdownloadcurses.py", "btdownloadheadless.py",
-           "btmaketorrentgui.py", "btmaketorrent.py",
+scripts = ["btdownloadcurses.py", "btdownloadheadless.py",
+           "btmaketorrent.py",
            "btlaunchmany.py", "btlaunchmanycurses.py", 
            "bttrack.py", "btreannounce.py", "btrename.py", "btshowmetainfo.py"]
@@ -27,4 +27,3 @@
 img_root, doc_root = BitTorrent.calc_unix_dirs()
 
-data_files = [ (img_root        , glob.glob('images/*png')+['images/bittorrent.ico',]),
-               (img_root+'/logo', glob.glob('images/logo/bittorrent_[0-9]*.png')     ),
+data_files = [ 

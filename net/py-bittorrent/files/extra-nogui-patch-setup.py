--- setup.py.orig	Tue Aug 23 22:58:45 2005
+++ setup.py	Tue Aug 23 23:09:21 2005
@@ -25,8 +25,8 @@
 
 import glob
 
-symlinks = ["bittorrent" , "bittorrent-curses", "bittorrent-console",
-           "maketorrent",                      "maketorrent-console",
+symlinks = ["bittorrent-curses", "bittorrent-console",
+            "maketorrent-console",
                           "launchmany-curses", "launchmany-console",
                                                "changetracker-console",
                                                "torrentinfo-console",
@@ -53,5 +53,5 @@
     translations.append (("%s/%s/LC_MESSAGES"          % (locale_root, l),
                           ["locale/%s/LC_MESSAGES/bittorrent.mo" % l]))
 
-data_files = [ (img_root        , glob.glob('images/*png')+['images/bittorrent.ico',]),
-               (img_root+'/logo', glob.glob('images/logo/bittorrent_[0-9]*.png')     ),
+data_files = [ 
+               

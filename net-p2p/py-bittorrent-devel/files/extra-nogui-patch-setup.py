--- setup.py.orig	Tue Jan 31 18:17:23 2006
+++ setup.py	Wed Feb  1 21:41:07 2006
@@ -38,8 +38,8 @@
 os.rmdir('FOO')
 # done detecting case-insensitive filesystem
 
-symlinks = ["bittorrent" , "bittorrent-curses", "bittorrent-console",
-           "maketorrent",                      "maketorrent-console",
+symlinks = ["bittorrent-curses", "bittorrent-console",
+            "maketorrent-console",
                           "launchmany-curses", "launchmany-console",
                                                "changetracker-console",
                                                "torrentinfo-console",
@@ -68,7 +68,5 @@
         translations.append((os.path.join(locale_root, l, 'LC_MESSAGES'), 
                              [path,]))
 
-data_files = [ (img_root        , glob.glob('images/*png')+['images/bittorrent.ico',]),
-               (img_root+'/logo', glob.glob('images/logo/bittorrent_[0-9]*.png'     )),
-               (img_root+'/icons/default', glob.glob('images/icons/default/*.png'   )),
-               (img_root+'/icons/old'    , glob.glob('images/icons/old/*.png'       )),
+data_files = [ 
+

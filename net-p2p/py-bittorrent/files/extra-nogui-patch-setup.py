--- setup.py.orig	Mon May  7 05:50:40 2007
+++ setup.py	Mon May  7 05:53:17 2007
@@ -46,7 +46,6 @@
-symlinks = ["bittorrent" ,
+symlinks = [
             "bittorrent-curses",
             "bittorrent-console",
-            "maketorrent",
             "maketorrent-console",
             "launchmany-curses",
             "launchmany-console",
@@ -81,1 +80,0 @@
-    (img_root, ['images/bittorrent.ico',]),
@@ -87,7 +87,0 @@
-for d in ('flags', 'logo', 'themes/default',
-          'themes/default/statuslight', 'themes/default/torrentstate',
-          'themes/default/torrentops' , 'themes/default/fileops'     ,):
-    data_files.append(
-        (os.path.join(img_root, d),
-         glob.glob(os.path.join('images', d, '*.png')))
-        )

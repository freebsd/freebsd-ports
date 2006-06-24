--- setup.py.orig	Sat Jun 24 16:54:04 2006
+++ setup.py	Sat Jun 24 16:54:55 2006
@@ -42,2 +42,2 @@
-symlinks = ["bittorrent" , "bittorrent-curses", "bittorrent-console",
-           "maketorrent",                      "maketorrent-console",
+symlinks = ["bittorrent-curses", "bittorrent-console",
+           "maketorrent-console",
@@ -68,1 +68,0 @@
-    (img_root, ['images/bittorrent.ico',]),
@@ -74,7 +74,0 @@
-for d in ('flags', 'logo', 'themes/default',
-          'themes/default/statuslight', 'themes/default/torrentstate',
-          'themes/default/torrentops' , 'themes/default/fileops'     ,):
-    data_files.append(
-        (os.path.join(img_root, d),
-         glob.glob(os.path.join('images', d, '*.png')))
-        )

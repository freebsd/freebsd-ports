
$FreeBSD$

--- setup.py.orig	Sun Apr  4 23:20:04 2004
+++ setup.py	Sun Apr  4 23:21:13 2004
@@ -23,8 +23,9 @@
         "btdownloadcurses.py", "btcompletedirgui.py", "btlaunchmanycurses.py", 
         "btmakemetafile.py", "btreannounce.py", "btrename.py", "btshowmetainfo.py",
         "bttest.py",
-        'btmaketorrentgui.py', 'btcopyannounce.py', 'btsethttpseeds.py', 'bt-t-make.py',
-        'alloc.gif','black1.ico','black.ico','blue.ico','green1.ico','green.ico',
+        'btmaketorrentgui.py', 'btcopyannounce.py', 'btsethttpseeds.py', 'bt-t-make.py'],
+     data_files=[('share/BitTornado', 
+        ['alloc.gif','black1.ico','black.ico','blue.ico','green1.ico','green.ico',
         'icon_bt.ico','icon_done.ico','red.ico','white.ico',
-        'yellow1.ico','yellow.ico']
+        'yellow1.ico','yellow.ico'])]
     )

--- setup.py.orig	Sat Apr  3 01:56:44 2004
+++ setup.py	Wed Apr 14 15:57:49 2004
@@ -18,13 +18,14 @@
     
     packages = ["BitTornado","BitTornado.BT1"],
 
-    scripts = ["btdownloadgui.py", "btdownloadheadless.py", "btdownloadlibrary.py", 
+    scripts = ["btdownloadheadless.py", "btdownloadlibrary.py", 
         "bttrack.py", "btmakemetafile.py", "btlaunchmany.py", "btcompletedir.py",
-        "btdownloadcurses.py", "btcompletedirgui.py", "btlaunchmanycurses.py", 
+        "btdownloadcurses.py", "btlaunchmanycurses.py", 
         "btmakemetafile.py", "btreannounce.py", "btrename.py", "btshowmetainfo.py",
         "bttest.py",
-        'btmaketorrentgui.py', 'btcopyannounce.py', 'btsethttpseeds.py', 'bt-t-make.py',
-        'alloc.gif','black1.ico','black.ico','blue.ico','green1.ico','green.ico',
+        'btcopyannounce.py', 'btsethttpseeds.py', 'bt-t-make.py'],
+     data_files=[('share/BitTornado', 
+        ['alloc.gif','black1.ico','black.ico','blue.ico','green1.ico','green.ico',
         'icon_bt.ico','icon_done.ico','red.ico','white.ico',
-        'yellow1.ico','yellow.ico']
+        'yellow1.ico','yellow.ico'])]
     )


$FreeBSD$

--- setup.py.orig	Sun May 16 13:40:26 2004
+++ setup.py	Tue May 25 10:21:43 2004
@@ -18,12 +18,16 @@
     
     packages = ["BitTornado","BitTornado.BT1"],
 
-    scripts = ["btdownloadgui.py", "btdownloadheadless.py", 
+    scripts = ["btdownloadheadless.py", 
         "bttrack.py", "btmakemetafile.py", "btlaunchmany.py", "btcompletedir.py",
-        "btdownloadcurses.py", "btcompletedirgui.py", "btlaunchmanycurses.py", 
+        "btdownloadcurses.py", "btlaunchmanycurses.py", 
         "btmakemetafile.py", "btreannounce.py", "btrename.py", "btshowmetainfo.py",
         "bttest.py",
-        'btmaketorrentgui.py', 'btcopyannounce.py', 'btsethttpseeds.py',
+        'btcopyannounce.py', 'btsethttpseeds.py',
         'bt-t-make.py',
-        ]
+        ],
+    data_files = [('share/BitTornado', 
+	['alloc.gif','black1.ico','black.ico','blue.ico','green1.ico','green.ico',
+          'icon_bt.ico','icon_done.ico','red.ico','white.ico',
+         'yellow1.ico','yellow.ico'])]
     )


$FreeBSD$

--- setup.py.orig	Wed Oct  6 11:50:10 2004
+++ setup.py	Fri Dec 17 17:42:32 2004
@@ -18,11 +18,15 @@
     
     packages = ["BitTornado","BitTornado.BT1"],
 
-    scripts = ["btdownloadgui.py", "btdownloadheadless.py", 
+    scripts = ["btdownloadheadless.py", 
         "bttrack.py", "btmakemetafile.py", "btlaunchmany.py", "btcompletedir.py",
-        "btdownloadcurses.py", "btcompletedirgui.py", "btlaunchmanycurses.py", 
+        "btdownloadcurses.py", "btlaunchmanycurses.py", 
         "btmakemetafile.py", "btreannounce.py", "btrename.py", "btshowmetainfo.py",
-        'btmaketorrentgui.py', 'btcopyannounce.py', 'btsethttpseeds.py',
+        'btcopyannounce.py', 'btsethttpseeds.py',
         'bt-t-make.py',
-        ]
+        ],
+    data_files = [('share/BitTornado', 
+	['icons/alloc.gif','icons/black1.ico','icons/black.ico','icons/blue.ico','icons/green1.ico','icons/green.ico',
+          'icons/icon_bt.ico','icons/icon_done.ico','icons/red.ico','icons/white.ico',
+         'icons/yellow1.ico','icons/yellow.ico'])]
     )

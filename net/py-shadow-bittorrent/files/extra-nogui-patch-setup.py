--- setup.py.old	Mon Feb 23 10:55:55 2004
+++ setup.py	Mon Feb 23 10:57:25 2004
@@ -18,10 +18,10 @@
     
     packages = ["BitTorrent"],
 
-    scripts = ["btdownloadgui.py", "btdownloadheadless.py", "btdownloadlibrary.py", 
+    scripts = ["btdownloadheadless.py", "btdownloadlibrary.py", 
         "bttrack.py", "btmakemetafile.py", "btlaunchmany.py", "btcompletedir.py",
-        "btdownloadcurses.py", "btcompletedirgui.py", "btlaunchmanycurses.py", 
+        "btdownloadcurses.py", "btlaunchmanycurses.py", 
         "btmakemetafile.py", "btreannounce.py", "btrename.py", "btshowmetainfo.py",
         "bttest.py",
-        'btmaketorrentgui.py', 'btcopyannounce.py', 'btsethttpseeds.py', 'bt-t-make.py' ]
+        'btcopyannounce.py', 'btsethttpseeds.py', 'bt-t-make.py' ]
     )

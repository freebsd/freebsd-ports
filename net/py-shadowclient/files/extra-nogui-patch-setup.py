--- setup.py.orig	Sun Feb 29 11:31:48 2004
+++ setup.py	Sun Feb 29 11:32:09 2004
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

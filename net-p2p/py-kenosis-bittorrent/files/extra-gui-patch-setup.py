--- setup.py.orig	Fri Jan 14 22:03:18 2005
+++ setup.py	Fri Jan 14 22:03:44 2005
@@ -9,18 +9,19 @@
 import BitTorrent
 
 setup(
-    name = "BitTorrent",
-    version = BitTorrent.version,
+    name = "%%KENOSIS-BITTORRENT%%",
+    version = %%KENOSIS-BITTORRENT%%.version,
     author = "Bram Cohen",
     author_email = "<bram@bitconjurer.org>",
     url = "http://www.bitconjurer.org/BitTorrent/",
     license = "MIT",
     
-    packages = ["BitTorrent"],
+    packages = ["%%KENOSIS-BITTORRENT%%"],
 
     scripts = ["btdownloadgui.py", "btdownloadheadless.py", "btdownloadlibrary.py", 
         "bttrack.py", "btmakemetafile.py", "btlaunchmany.py", "btcompletedir.py",
         "btdownloadcurses.py", "btcompletedirgui.py", "btlaunchmanycurses.py", 
         "btmakemetafile.py", "btreannounce.py", "btrename.py", "btshowmetainfo.py",
+	"btunittest.py",
         "bttest.py"]
     )

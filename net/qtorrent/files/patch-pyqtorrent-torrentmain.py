--- pyqtorrent/torrentmain.py.orig	Sat Dec 31 11:43:19 2005
+++ pyqtorrent/torrentmain.py	Sat Dec 31 11:43:31 2005
@@ -501,7 +501,7 @@
             torrent.start()
     
     def openFile(self):
-        fn = QFileDialog.getOpenFileName(None, "*.torrent")
+        fn = QFileDialog.getOpenFileName("*.torrent")
         if fn:
             self.newTorrent(str(fn))
     

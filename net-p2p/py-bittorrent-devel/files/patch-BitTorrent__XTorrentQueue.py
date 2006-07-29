--- ./BitTorrent/XTorrentQueue.py.orig	Fri Jul 28 23:27:55 2006
+++ ./BitTorrent/XTorrentQueue.py	Fri Jul 28 23:28:20 2006
@@ -32,10 +32,10 @@
             
         return Binary(infohash)
     
-    def _create_torrent(self, torrent, dlpath):
+    def _create_torrent(self, torrent, save_incomplete_as, save_as):
         d = bdecode(torrent)
         metainfo = ConvertedMetainfo(d)
-        self.tq.create_torrent(metainfo, dlpath)
+        self.tq.create_torrent(metainfo, save_incomplete_as, save_as)
         return metainfo.infohash
 
     def xmlrpc_start_torrent(self, infohash):

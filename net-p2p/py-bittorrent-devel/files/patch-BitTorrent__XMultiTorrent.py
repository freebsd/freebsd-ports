--- ./BitTorrent/XMultiTorrent.py.orig	Fri Jul 28 23:25:45 2006
+++ ./BitTorrent/XMultiTorrent.py	Fri Jul 28 23:27:31 2006
@@ -50,10 +50,10 @@
             
         return Binary(infohash)
     
-    def _create_torrent(self, torrent, dlpath):
+    def _create_torrent(self, torrent, save_incomplete_as, save_as):
         d = bdecode(torrent)
         metainfo = ConvertedMetainfo(d)
-        self.multitorrent.create_torrent(metainfo, dlpath)
+        self.multitorrent.create_torrent(metainfo, save_incomplete_as, save_as)
         return metainfo.infohash
 
     def xmlrpc_start_torrent(self, infohash):

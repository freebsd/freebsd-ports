--- ./BitTorrent/MultiTorrent.py.orig	Mon Jul 24 00:58:59 2006
+++ ./BitTorrent/MultiTorrent.py	Sat Jul 29 00:02:03 2006
@@ -270,6 +270,8 @@
         self.logger.log(severity, message, exc_info=exc_info)
 
     def create_torrent(self, metainfo, save_incomplete_as, save_as,
+                       saveas_style_save_incomplete_as=None,
+                       saveas_style_save_as=None,
                        hidden=False, is_auto_update=False):
         if self.is_single_torrent and len(self.torrents) > 0:
             print "create_torrent: len(self.torrents)=", len(self.torrents)
@@ -295,9 +297,11 @@
                                                 infohash,
                                                 lambda s : self.global_error(logging.ERROR, s))
 
-        t = Torrent(metainfo, save_incomplete_as, save_as, self.config,
-                    self.data_dir, self.rawserver, self.choker,
-                    self.singleport_listener, self.ratelimiter,
+        t = Torrent(metainfo, save_incomplete_as, save_as,
+                    saveas_style_save_incomplete_as,
+                    saveas_style_save_as,
+                    self.config, self.data_dir, self.rawserver,
+                    self.choker, self.singleport_listener, self.ratelimiter,
                     self.total_downmeasure, self.filepool, self.dht, self,
                     self.log_root, hidden=hidden, is_auto_update=is_auto_update)
         retdf = Deferred()
@@ -686,7 +690,7 @@
                                   '('+unicode(e.args[0])+')')
                 return None
 
-            t = Torrent(metainfo, "",  "", self.config, self.data_dir,
+            t = Torrent(metainfo, "", "", "", "", self.config, self.data_dir,
                         self.rawserver, self.choker,
                         self.singleport_listener, self.ratelimiter,
                         self.total_downmeasure, self.filepool, self.dht, self,

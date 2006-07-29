--- ./BitTorrent/AutoUpdateButler.py.orig	Fri Jul 28 23:30:10 2006
+++ ./BitTorrent/AutoUpdateButler.py	Fri Jul 28 23:29:47 2006
@@ -375,7 +375,7 @@
                 self.multitorrent.remove_auto_updates_except(infohash)
 
                 try:
-                    df = self.multitorrent.create_torrent(metainfo, installer_path, installer_path, hidden=True, is_auto_update=True)
+                    df = self.multitorrent.create_torrent(metainfo, installer_path, installer_path, installer_path, installer_path, hidden=True, is_auto_update=True)
                     yield df
                     df.getResult()
                 except TorrentAlreadyRunning:

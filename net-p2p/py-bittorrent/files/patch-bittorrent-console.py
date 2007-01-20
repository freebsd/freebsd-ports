--- bittorrent-console.py.orig	Sat Dec 16 08:54:46 2006
+++ bittorrent-console.py	Sat Dec 16 08:55:07 2006
@@ -39,7 +39,7 @@
 from BTL import GetTorrent
 from BTL.ConvertedMetainfo import ConvertedMetainfo
 from BitTorrent.MultiTorrent import TorrentNotInitialized
-from BitTorrent.RawServer_twisted import RawServer, task
+from BitTorrent.RawServer_twisted import RawServer
 from BitTorrent.UI import Size, Duration
 inject_main_logfile()
 from BitTorrent import console
@@ -326,12 +326,12 @@
             if config['save_in']:
                 raise BTFailure(_("You cannot specify both --save_as and "
                                   "--save_in."))
-            saveas,bad = platform.encode_for_filesystem(config['save_as'])
+            saveas,bad = encode_for_filesystem(config['save_as'])
             if bad:
                 raise BTFailure(_("Invalid path encoding."))
             savein = os.path.dirname(os.path.abspath(saveas))
         elif config['save_in']:
-            savein,bad = platform.encode_for_filesystem(config['save_in'])
+            savein,bad = encode_for_filesystem(config['save_in'])
             if bad:
                 raise BTFailure(_("Invalid path encoding."))
             saveas = os.path.join(savein,torrent_name)
@@ -339,14 +339,14 @@
             saveas = torrent_name
         if config['save_incomplete_in']:
             save_incomplete_in,bad = \
-                platform.encode_for_filesystem(config['save_incomplete_in'])
+                encode_for_filesystem(config['save_incomplete_in'])
             if bad:
                 raise BTFailure(_("Invalid path encoding."))
             save_incomplete_as = os.path.join(save_incomplete_in,torrent_name)
         else:
             save_incomplete_as = os.path.join(savein,torrent_name)
     
-        data_dir,bad = platform.encode_for_filesystem(config['data_dir'])
+        data_dir,bad = encode_for_filesystem(config['data_dir'])
         if bad:
             raise BTFailure(_("Invalid path encoding."))
 

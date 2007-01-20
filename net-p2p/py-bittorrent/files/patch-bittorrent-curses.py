--- bittorrent-curses.py.orig	Sat Dec 16 08:55:22 2006
+++ bittorrent-curses.py	Sat Dec 16 08:55:49 2006
@@ -42,7 +42,7 @@
 from BitTorrent import BTFailure, UserFailure
 from BitTorrent import version
 from BTL import GetTorrent
-from BitTorrent.RawServer_twisted import RawServer, task
+from BitTorrent.RawServer_twisted import RawServer
 from BTL.ConvertedMetainfo import ConvertedMetainfo
 from BTL.yielddefer import launch_coroutine, _wrap_task
 from BitTorrent import inject_main_logfile
@@ -498,12 +498,12 @@
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
@@ -511,14 +511,14 @@
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
 

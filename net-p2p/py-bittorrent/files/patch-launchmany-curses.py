--- launchmany-curses.py.orig	Sat Dec 16 08:49:21 2006
+++ launchmany-curses.py	Sat Dec 16 08:50:18 2006
@@ -316,10 +316,10 @@
         if args:
             torrent_dir = args[0]
             config['torrent_dir'] = \
-                platform.decode_from_filesystem(torrent_dir)    
+                decode_from_filesystem(torrent_dir)    
         else:
             torrent_dir = config['torrent_dir']
-            torrent_dir,bad = platform.encode_for_filesystem(torrent_dir)
+            torrent_dir,bad = encode_for_filesystem(torrent_dir)
             if bad:
               raise BTFailure(_("Warning: ")+config['torrent_dir']+
                               _(" is not a directory"))

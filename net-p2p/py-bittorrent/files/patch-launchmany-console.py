--- launchmany-console.py.orig	Sat Dec 16 08:53:05 2006
+++ launchmany-console.py	Sat Dec 16 08:53:27 2006
@@ -80,10 +80,10 @@
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

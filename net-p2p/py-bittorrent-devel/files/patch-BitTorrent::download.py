--- BitTorrent.orig/download.py	Mon Dec 20 20:39:15 2004
+++ BitTorrent/download.py	Wed Dec 29 01:13:08 2004
@@ -144,7 +144,11 @@
             if filelist:
                 return None
             return 1
-        s = Storage(None, None, zip(myfiles, metainfo.sizes), check_only=True)
+        try:
+            s = Storage(None, None, zip(myfiles, metainfo.sizes),
+                        check_only=True)
+        except:
+            return None
         filename = os.path.join(config['data_dir'], 'resume',
                                 infohash.encode('hex'))
         try:

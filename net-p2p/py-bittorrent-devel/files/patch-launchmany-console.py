--- ./launchmany-console.py.orig	Wed Jul 12 02:18:54 2006
+++ ./launchmany-console.py	Fri Jul 28 23:56:07 2006
@@ -49,6 +49,10 @@
                 uprate/1000, dnrate/1000, upamt/1024, dnamt/1024, msg))
         return False
 
+    def exception(self, s):
+        exceptions.append(s)
+        #logging.getLogger('').info(_("SYSTEM ERROR - EXCEPTION GENERATED"))
+
 
 if __name__ == '__main__':
     uiname = 'launchmany-console'
@@ -76,7 +80,7 @@
                 platform.decode_from_filesystem(torrent_dir)
         else:
             torrent_dir = config['torrent_dir']
-            torrent_dir,bad = platform.encode_from_filesystem(torrent_dir)
+            torrent_dir,bad = platform.encode_for_filesystem(torrent_dir)
             if bad:
               raise BTFailure(_("Warning: ")+config['torrent_dir']+
                               _(" is not a directory"))
@@ -139,4 +143,8 @@
     #logging.getLogger().setLevel(INFO)
     logging.getLogger('').setLevel(0)
     
-    LaunchMany(config, d.display, 'launchmany-console')
+    LaunchMany(config, d, 'launchmany-console')
+
+    if exceptions:
+        print _("\nEXCEPTION:")
+        print exceptions[0]

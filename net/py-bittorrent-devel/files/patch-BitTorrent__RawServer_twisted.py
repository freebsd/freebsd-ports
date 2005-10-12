--- BitTorrent/RawServer_twisted.py.orig	Wed Oct 12 08:56:50 2005
+++ BitTorrent/RawServer_twisted.py	Wed Oct 12 09:01:36 2005
@@ -565,7 +565,7 @@
         bindaddr = None
         if do_bind:
             bindaddr = self.config['bind']
-            if bindaddr and len(binadder) >= 0:
+            if bindaddr and len(bindaddr) >= 0:
                 bindaddr = (bindaddr, 0)
             else:
                 bindaddr = None

--- ./BitTorrent/Torrent.py.orig	Mon Jun 12 22:45:53 2006
+++ ./BitTorrent/Torrent.py	Wed Jun 21 23:57:08 2006
@@ -234,6 +234,9 @@
     def is_running(self):
         return self.state == "running"
 
+    def is_seeding(self):
+        return self._activity == (_("seeding"), 1)
+
     def is_context_valid(self):
         return self.context_valid

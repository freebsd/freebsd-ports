--- BitTorrent.orig/Downloader.py	Mon Dec 20 20:39:14 2004
+++ BitTorrent/Downloader.py	Wed Dec 29 01:13:08 2004
@@ -205,7 +205,7 @@
                 self.connection.send_interested()
             self.example_interest = interest
             self.downloader.picker.requested(interest, self.have.numfalse == 0)
-            while len(self.active_requests) < self.backlog * 2:
+            while len(self.active_requests) < (self.backlog-2) * 5 + 2:
                 begin, length = self.downloader.storage.new_request(interest)
                 self.active_requests.append((interest, begin, length))
                 self.connection.send_request(interest, begin, length)

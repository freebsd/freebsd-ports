
$FreeBSD$

--- BitTornado/BT1/Rerequester.py.orig	Tue Sep 14 19:32:11 2004
+++ BitTornado/BT1/Rerequester.py	Tue Sep 14 19:33:00 2004
@@ -115,7 +115,7 @@
             if self.howmany() >= self.maxpeers:
                 s += '&numwant=0'
             else:
-                s += '&no_peer_id=1&compact=1'
+                s += '&no_peer_id=1'
             self.last_failed = True         # force true, so will display an error
             self.special = specialurl
             self.rerequest(s, callback)
@@ -132,7 +132,7 @@
         if self.howmany() >= self.maxpeers:
             s += '&numwant=0'
         else:
-            s += '&no_peer_id=1&compact=1'
+            s += '&no_peer_id=1'
         if event != 3:
             s += '&event=' + ['started', 'completed', 'stopped'][event]
             
@@ -384,4 +384,4 @@
         self.lock.acquire()
         x = self.finished
         self.lock.release()
-        return x    
\ No newline at end of file
+        return x    

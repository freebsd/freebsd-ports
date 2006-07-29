--- ./BitTorrent/Rerequester.py.orig	Wed Jul 12 02:18:25 2006
+++ ./BitTorrent/Rerequester.py	Sat Jul 22 17:42:24 2006
@@ -369,7 +369,8 @@
     def _postrequest(self, data=None, errormsg=None, exc=None, peerid=None):
         assert thread.get_ident() == self.rawserver.ident
         self.current_started = None
-        self.errorfunc(logging.INFO, 'postrequest: ' + str(self.current_started))
+        if self.current_started is not None:
+            self.errorfunc(logging.INFO, 'postrequest: ' + str(self.current_started))
         self.last_time = bttime()
         if self.dead:
             return

--- BitTorrent/Rerequester.py.orig	Sat Jun 24 08:14:52 2006
+++ BitTorrent/Rerequester.py	Sat Jun 24 08:22:14 2006
@@ -180,8 +180,8 @@
     def _check(self):
         assert thread.get_ident() == self.rawserver.ident
         assert not self.dead
-        self.errorfunc(logging.INFO, 'check: ' + str(self.current_started))
         if self.current_started is not None:
+            self.errorfunc(logging.INFO, 'check: ' + str(self.current_started))
             if self.current_started <= bttime() - 58:
                 self.errorfunc(logging.WARNING,
                                _("Tracker announce still not complete "
@@ -352,7 +352,8 @@
     def _postrequest(self, data=None, errormsg=None, exc=None, peerid=None):
         assert thread.get_ident() == self.rawserver.ident
         self.current_started = None
-        self.errorfunc(logging.INFO, 'postrequest: ' + str(self.current_started))
+        if self.current_started is not None:
+            self.errorfunc(logging.INFO, 'postrequest: ' + str(self.current_started))
         self.last_time = bttime()
         if self.dead:
             return

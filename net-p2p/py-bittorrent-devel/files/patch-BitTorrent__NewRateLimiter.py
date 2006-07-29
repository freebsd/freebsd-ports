--- ./BitTorrent/NewRateLimiter.py.orig	Wed Jul 12 02:18:21 2006
+++ ./BitTorrent/NewRateLimiter.py	Sat Jul 22 17:42:24 2006
@@ -144,24 +144,14 @@
     def restart_loop(self, t):
         # check for pending loop event
         if self.task and not self.task.called:
-            ## look at when it's scheduled to occur
-            # we can special case events which have a delta of 0, since they
-            # should occur asap. no need to check the time.
-            if self.task.delta == 0:
-                return
-            # use time.time since twisted does anyway
-            s = self.task.getTime() - time.time()
-            if s > t:
-                # if it would occur after the time we want, reset it
-                self.task.reset(t)
-                self.task.delta = t
-        else:
-            if t == 0:
-                # don't spin the event loop needlessly
-                self.run()
-            else:
-                self.task = self.add_task(t, self.run)
-                self.task.delta = t
+            # look at when it's scheduled to occur
+            s = self.task.getTime() - bttime()
+            if s <= t:
+                return 
+            # if it would occur after the time we want, cancel it
+            self.task.cancel()
+
+        self.task = self.add_task(t, self.run)
 
     def _write(self, to_write):
         amount = 0

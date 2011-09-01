--- msrplib/session.py.orig	2011-07-16 22:38:18.000000000 +0700
+++ msrplib/session.py	2011-07-16 22:38:31.000000000 +0700
@@ -391,7 +391,7 @@
         If chunk's Failure-Report is 'no', return None immediately.
         """
         if chunk.failure_report!='no' and event is None:
-            event = coros.event()
+            event = event.Event()
         self.send_chunk(chunk, event.send)
         if event is not None:
             response = event.wait()

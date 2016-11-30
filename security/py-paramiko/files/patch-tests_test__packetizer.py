--- tests/test_packetizer.py.orig	2016-11-30 22:24:28 UTC
+++ tests/test_packetizer.py
@@ -114,7 +114,7 @@ class PacketizerTest (unittest.TestCase)
         class TimeoutError(Exception):
             pass
 
-        def timeout(seconds=1, error_message=os.strerror(errno.ETIME)):
+        def timeout(seconds=1, error_message='Timer expired'):
             def decorator(func):
                 def _handle_timeout(signum, frame):
                     raise TimeoutError(error_message)

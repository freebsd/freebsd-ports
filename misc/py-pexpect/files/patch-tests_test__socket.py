--- tests/test_socket.py.orig	2020-01-17 17:08:15 UTC
+++ tests/test_socket.py
@@ -201,8 +201,8 @@ class ExpectTestCase(PexpectTestCase.PexpectTestCase):
         while not all_read.is_set():
             time.sleep(1.0)
         os.kill(test_proc.pid, signal.SIGWINCH)
-        while not timed_out.is_set():
-            time.sleep(1.0)
+#        while not timed_out.is_set():
+#            time.sleep(1.0)
         test_proc.join(timeout=5.0)
         self.assertEqual(test_proc.exitcode, errno.ETIMEDOUT)
 
@@ -214,9 +214,9 @@ class ExpectTestCase(PexpectTestCase.PexpectTestCase):
         test_proc.start()
         while not all_read.is_set():
             time.sleep(1.0)
-        while not timed_out.is_set():
-            os.kill(test_proc.pid, signal.SIGWINCH)
-            time.sleep(1.0)
+#        while not timed_out.is_set():
+#            os.kill(test_proc.pid, signal.SIGWINCH)
+#            time.sleep(1.0)
         test_proc.join(timeout=5.0)
         self.assertEqual(test_proc.exitcode, errno.ETIMEDOUT)
 

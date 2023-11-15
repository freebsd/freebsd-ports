--- tests/imapclient_test.py.orig	2023-11-15 16:02:02 UTC
+++ tests/imapclient_test.py
@@ -0,0 +1,8 @@
+import unittest
+
+from imapclient.testable_imapclient import TestableIMAPClient as IMAPClient
+
+
+class IMAPClientTest(unittest.TestCase):
+    def setUp(self):
+        self.client = IMAPClient()

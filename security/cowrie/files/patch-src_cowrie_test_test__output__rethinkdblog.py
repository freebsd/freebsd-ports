-- Skip rethinkdb output test when rethinkdb is not installed
-- These optional backend tests require packages not available in ports.
-- Skip rethinkdb output test when rethinkdb is not installed
-- These optional backend tests require packages not available in ports.
--- src/cowrie/test/test_output_rethinkdblog.py.orig	2026-10-21 09:10:14 UTC
+++ src/cowrie/test/test_output_rethinkdblog.py
@@ -7,6 +7,12 @@ from __future__ import annotations
 
 from __future__ import annotations
 
+try:
+    import rethinkdb
+except ImportError:
+    import unittest
+    raise unittest.SkipTest("rethinkdb not available")
+
 import base64
 import hashlib
 import hmac

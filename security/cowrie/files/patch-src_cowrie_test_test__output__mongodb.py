-- Skip mongodb output test when txmongo is not installed
-- These optional backend tests require packages not available in ports.
-- Skip mongodb output test when txmongo is not installed
-- These optional backend tests require packages not available in ports.
--- src/cowrie/test/test_output_mongodb.py.orig	2026-10-21 09:10:13 UTC
+++ src/cowrie/test/test_output_mongodb.py
@@ -7,6 +7,12 @@ from __future__ import annotations
 
 from __future__ import annotations
 
+try:
+    import txmongo
+except ImportError:
+    import unittest
+    raise unittest.SkipTest("txmongo not available")
+
 import os
 import tempfile
 import unittest

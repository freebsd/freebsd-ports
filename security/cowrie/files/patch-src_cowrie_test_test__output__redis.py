-- Skip redis output test when txredisapi is not installed
-- These optional backend tests require packages not available in ports.
-- Skip redis output test when txredisapi is not installed
-- These optional backend tests require packages not available in ports.
--- src/cowrie/test/test_output_redis.py.orig	2026-10-21 09:10:14 UTC
+++ src/cowrie/test/test_output_redis.py
@@ -7,6 +7,12 @@ from __future__ import annotations
 
 from __future__ import annotations
 
+try:
+    import txredisapi
+except ImportError:
+    import unittest
+    raise unittest.SkipTest("txredisapi not available")
+
 import json
 import os
 import tempfile

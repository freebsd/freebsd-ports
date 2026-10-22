-- Skip RMQ output test when pika is not installed
-- These optional backend tests require packages not available in ports.
-- Skip RMQ output test when pika is not installed
-- These optional backend tests require packages not available in ports.
--- src/cowrie/test/test_output_rmq.py.orig	2026-10-21 09:10:14 UTC
+++ src/cowrie/test/test_output_rmq.py
@@ -7,6 +7,12 @@ from __future__ import annotations
 
 from __future__ import annotations
 
+try:
+    import pika
+except ImportError:
+    import unittest
+    raise unittest.SkipTest("pika not available")
+
 import json
 import os
 import tempfile

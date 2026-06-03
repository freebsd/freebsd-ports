--- test/jit/test_with.py.orig	2026-04-18 21:49:29 UTC
+++ test/jit/test_with.py
@@ -3,6 +3,7 @@ import sys
 
 import os
 import sys
+import unittest
 from typing import Any, List
 
 import torch
@@ -609,6 +610,10 @@ class TestWith(JitTestCase):
         self.assertFalse(w.requires_grad)
 
     @skipIfTorchDynamo("Torchdynamo cannot correctly handle profiler.profile calls")
+    @unittest.skipIf(
+        sys.platform.startswith("freebsd"),
+        "Hangs on FreeBSD due to profiler/JIT interaction deadlock",
+    )
     def test_with_record_function(self):
         """
         Check that torch.autograd.profiler.record_function context manager is

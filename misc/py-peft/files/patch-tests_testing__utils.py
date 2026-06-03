--- tests/testing_utils.py.orig	2026-04-15 06:22:00 UTC
+++ tests/testing_utils.py
@@ -177,11 +177,15 @@ def require_bitsandbytes(test_case):
 
 def require_bitsandbytes(test_case):
     """
-    Decorator marking a test that requires the bitsandbytes library. Will be skipped when the library is not installed.
+    Decorator marking a test that requires the bitsandbytes library. Will be skipped when the library is not installed
+    or when CUDA is not available (8-bit optimizers require CUDA).
     """
     try:
         import bitsandbytes  # noqa: F401
+        import torch
 
+        if not torch.cuda.is_available():
+            return pytest.mark.skip(reason="test requires bitsandbytes with CUDA")(test_case)
         test_case = pytest.mark.bitsandbytes(test_case)
     except ImportError:
         test_case = pytest.mark.skip(reason="test requires bitsandbytes")(test_case)

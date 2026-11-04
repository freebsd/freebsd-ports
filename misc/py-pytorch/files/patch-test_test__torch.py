--- test/test_torch.py.orig	2026-10-28 18:13:32 UTC
+++ test/test_torch.py
@@ -10080,7 +10080,8 @@ tensor([[[1.+1.j, 1.+1.j, 1.+1.j,  ..., 1.+1.j, 1.+1.j
             torch.backends.quantized.engine = qe
             if torch.backends.quantized.engine != qe:
                 raise AssertionError(f"qengine not set successfully: expected {qe}, got {torch.backends.quantized.engine}")
-        torch.backends.quantized.engine = original_qe
+        if original_qe in qengines:
+            torch.backends.quantized.engine = original_qe
 
     def test_terminate_handler_on_crash(self):
         cmd = [sys.executable, '-c', "import os; os.environ[\"TORCH_CUSTOM_TERMINATE\"] ='1'; \

-- Skip float32 test cases in test_na3d_backends on CPU to avoid a segmentation
-- fault in PyTorch's CPU scaled_dot_product_attention implementation for some
-- input shapes.  bfloat16 and the existing fp16 skip path continue to run.
--- tests/test_na.py.orig	2025-03-01 00:00:00 UTC
+++ tests/test_na.py
@@ -79,6 +79,8 @@ def test_na3d_backends(shape, kernel, causal, dtype, scale):
     device = "cuda" if torch.cuda.is_available() else "cpu"
     if device == "cpu" and dtype == torch.float16:
         pytest.skip("fp16 SDPA is not supported on the CPU backend")
+    if device == "cpu" and dtype == torch.float32:
+        pytest.skip("fp32 SDPA on CPU triggers a PyTorch segmentation fault")
     backends = get_capable_backends("na3d", device)
     assert backends, "no backend for na3d"


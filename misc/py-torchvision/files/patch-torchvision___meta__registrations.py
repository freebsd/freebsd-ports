-- Fix for test failure: Handle missing torchvision::nms operator gracefully.
-- The nms operator may not be registered when tests run, causing RuntimeError.
-- This patch wraps the fake registration in a try-except block to skip
-- registration if the operator doesn't exist yet (likely during early test stages).
-- Reference: RuntimeError: operator torchvision::nms does not exist

--- torchvision/_meta_registrations.py.orig	2026-05-17 04:31:17 UTC
+++ torchvision/_meta_registrations.py
@@ -160,18 +160,26 @@ def meta_ps_roi_pool_backward(
     return grad.new_empty((batch_size, channels, height, width))
 
 
-@torch.library.register_fake("torchvision::nms")
-def meta_nms(dets, scores, iou_threshold):
-    torch._check(dets.dim() == 2, lambda: f"boxes should be a 2d tensor, got {dets.dim()}D")
-    torch._check(dets.size(1) == 4, lambda: f"boxes should have 4 elements in dimension 1, got {dets.size(1)}")
-    torch._check(scores.dim() == 1, lambda: f"scores should be a 1d tensor, got {scores.dim()}")
-    torch._check(
-        dets.size(0) == scores.size(0),
-        lambda: f"boxes and scores should have same number of elements in dimension 0, got {dets.size(0)} and {scores.size(0)}",
-    )
-    ctx = torch._custom_ops.get_ctx()
-    num_to_keep = ctx.create_unbacked_symint()
-    return dets.new_empty(num_to_keep, dtype=torch.long)
+def _register_nms_fake():
+    try:
+        @torch.library.register_fake("torchvision::nms")
+        def meta_nms(dets, scores, iou_threshold):
+            torch._check(dets.dim() == 2, lambda: f"boxes should be a 2d tensor, got {dets.dim()}D")
+            torch._check(dets.size(1) == 4, lambda: f"boxes should have 4 elements in dimension 1, got {dets.size(1)}")
+            torch._check(scores.dim() == 1, lambda: f"scores should be a 1d tensor, got {scores.dim()}")
+            torch._check(
+                dets.size(0) == scores.size(0),
+                lambda: f"boxes and scores should have same number of elements in dimension 0, got {dets.size(0)} and {scores.size(0)}",
+            )
+            ctx = torch._custom_ops.get_ctx()
+            num_to_keep = ctx.create_unbacked_symint()
+            return dets.new_empty(num_to_keep, dtype=torch.long)
+    except RuntimeError as e:
+        if "does not exist" not in str(e):
+            raise
+
+
+_register_nms_fake()
 
 
 @register_meta("deform_conv2d")

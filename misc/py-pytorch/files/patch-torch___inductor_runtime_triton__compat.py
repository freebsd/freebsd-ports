--- torch/_inductor/runtime/triton_compat.py.orig	2026-04-19 02:47:11 UTC
+++ torch/_inductor/runtime/triton_compat.py
@@ -8,7 +8,8 @@ try:
 
 try:
     import triton
-except ImportError:
+    import triton.language  # Verify it's a real install, not a namespace package
+except (ImportError, AttributeError):
     triton = None
 
 

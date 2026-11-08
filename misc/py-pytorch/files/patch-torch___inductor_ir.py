--- torch/_inductor/ir.py.orig	2026-10-28 18:16:03 UTC
+++ torch/_inductor/ir.py
@@ -161,7 +161,7 @@ try:
 
     triton_version = triton.__version__
     has_triton = True
-except ImportError:
+except (ImportError, AttributeError):
     triton_version = None
     has_triton = False
 

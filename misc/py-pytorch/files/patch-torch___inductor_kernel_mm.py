--- torch/_inductor/kernel/mm.py.orig	2026-10-28 18:16:03 UTC
+++ torch/_inductor/kernel/mm.py
@@ -96,7 +96,7 @@ try:
 
     triton_version = TorchVersion(triton.__version__)
     has_triton = True
-except ImportError:
+except (ImportError, AttributeError):
     triton_version = TorchVersion("0.0.0")
     has_triton = False
 

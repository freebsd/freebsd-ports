--- torch/_inductor/kernel/mm.py.orig	2026-04-19 02:49:11 UTC
+++ torch/_inductor/kernel/mm.py
@@ -70,7 +70,7 @@ try:
 
     triton_version = TorchVersion(triton.__version__)
     has_triton = True
-except ImportError:
+except (ImportError, AttributeError):
     triton_version = TorchVersion("0.0.0")
     has_triton = False
 

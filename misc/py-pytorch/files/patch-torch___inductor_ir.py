--- torch/_inductor/ir.py.orig	2026-05-13 17:40:44 UTC
+++ torch/_inductor/ir.py
@@ -137,7 +137,7 @@ try:
 
     triton_version = triton.__version__
     has_triton = True
-except ImportError:
+except (ImportError, AttributeError):
     triton_version = None
     has_triton = False
 

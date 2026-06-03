--- torch/_inductor/compile_worker/__main__.py.orig	2026-04-19 02:49:11 UTC
+++ torch/_inductor/compile_worker/__main__.py
@@ -30,7 +30,7 @@ try:
     import triton
 
     assert triton is not None  # preload in parent
-except ImportError:
+except (ImportError, AttributeError):
     pass
 
 

--- torch/_inductor/compile_worker/__main__.py.orig	2026-09-02 17:44:01 UTC
+++ torch/_inductor/compile_worker/__main__.py
@@ -31,7 +31,7 @@ try:
 
     if triton is None:
         raise AssertionError("triton failed to preload in parent")
-except ImportError:
+except (ImportError, AttributeError):
     pass
 
 

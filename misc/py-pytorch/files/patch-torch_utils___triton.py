--- torch/utils/_triton.py.orig	2026-10-28 18:16:03 UTC
+++ torch/utils/_triton.py
@@ -41,9 +41,10 @@ def has_triton_package() -> bool:
 def has_triton_package() -> bool:
     try:
         import triton  # noqa: F401
+        import triton.language  # noqa: F401  # Verify it's a real install, not a namespace pkg
 
         return True
-    except ImportError:
+    except (ImportError, AttributeError):
         return False
 
 

--- python/dgl/backend/__init__.py.orig	2023-05-08 05:34:30 UTC
+++ python/dgl/backend/__init__.py
@@ -115,8 +115,8 @@ def get_preferred_backend():
             "Assuming PyTorch for now.",
             file=sys.stderr,
         )
-        set_default_backend(default_dir, "pytorch")
-        return "pytorch"
+        set_default_backend(default_dir, "tensorflow")
+        return "tensorflow"
 
 
 load_backend(get_preferred_backend())

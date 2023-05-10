--- dgl/sparse/__init__.py.orig	2023-05-09 03:28:28 UTC
+++ dgl/sparse/__init__.py
@@ -22,6 +22,8 @@ def load_dgl_sparse():
 
     if sys.platform.startswith("linux"):
         basename = f"libdgl_sparse_pytorch_{version}.so"
+    elif sys.platform.startswith("freebsd"):
+        basename = f"libdgl_sparse_pytorch_{version}.so"
     elif sys.platform.startswith("darwin"):
         basename = f"libdgl_sparse_pytorch_{version}.dylib"
     elif sys.platform.startswith("win"):

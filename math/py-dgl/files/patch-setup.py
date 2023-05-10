--- setup.py.orig	2023-05-08 19:54:39 UTC
+++ setup.py
@@ -49,6 +49,8 @@ def get_lib_path():
 def get_ta_lib_pattern():
     if sys.platform.startswith("linux"):
         ta_lib_pattern = "libtensoradapter_*.so"
+    elif sys.platform.startswith("freebsd"):
+        ta_lib_pattern = "libtensoradapter_*.so"
     elif sys.platform.startswith("darwin"):
         ta_lib_pattern = "libtensoradapter_*.dylib"
     elif sys.platform.startswith("win"):
@@ -60,6 +62,8 @@ def get_ta_lib_pattern():
 
 def get_dgl_sparse_pattern():
     if sys.platform.startswith("linux"):
+        dgl_sparse_lib_pattern = "libdgl_sparse_*.so"
+    elif sys.platform.startswith("freebsd"):
         dgl_sparse_lib_pattern = "libdgl_sparse_*.so"
     elif sys.platform.startswith("darwin"):
         dgl_sparse_lib_pattern = "libdgl_sparse_*.dylib"

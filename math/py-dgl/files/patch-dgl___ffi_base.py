--- dgl/_ffi/base.py.orig	2023-05-09 03:27:48 UTC
+++ dgl/_ffi/base.py
@@ -137,6 +137,8 @@ def load_tensor_adapter(backend, version):
     version = version.split("+")[0]
     if sys.platform.startswith("linux"):
         basename = "libtensoradapter_%s_%s.so" % (backend, version)
+    elif sys.platform.startswith("freebsd"):
+        basename = "libtensoradapter_%s_%s.so" % (backend, version)
     elif sys.platform.startswith("darwin"):
         basename = "libtensoradapter_%s_%s.dylib" % (backend, version)
     elif sys.platform.startswith("win"):

--- torch/testing/_internal/torchbind_impls.py.orig	2026-05-13 17:40:45 UTC
+++ torch/testing/_internal/torchbind_impls.py
@@ -180,6 +180,8 @@ def load_torchbind_test_lib():
         lib_file_path = find_library_location("torchbind_test.dll")
     else:
         lib_file_path = find_library_location("libtorchbind_test.so")
+    if not Path(str(lib_file_path)).exists():
+        raise unittest.SkipTest(f"libtorchbind_test library not found (C++ test library not built)")
     torch.ops.load_library(str(lib_file_path))
 
 

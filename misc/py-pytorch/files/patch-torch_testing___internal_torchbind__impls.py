--- torch/testing/_internal/torchbind_impls.py.orig	2026-10-28 18:16:03 UTC
+++ torch/testing/_internal/torchbind_impls.py
@@ -186,6 +186,8 @@ def load_torchbind_test_lib():
             lib_file_path = find_library_location("torchbind_test.dll")
         else:
             lib_file_path = find_library_location("libtorchbind_test.so")
+    if not Path(str(lib_file_path)).exists():
+        raise unittest.SkipTest(f"libtorchbind_test library not found (C++ test library not built)")
 
         if not lib_file_path.exists():
             raise unittest.SkipTest(

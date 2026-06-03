--- test/test_fx.py.orig	2026-05-13 17:40:38 UTC
+++ test/test_fx.py
@@ -252,9 +252,12 @@ class TestFX(JitTestCase):
         )
         torch.fx.proxy.TracerBase.check_mutable_operations = True
 
+        self._torchbind_test_loaded = False
         if not (IS_FBCODE or IS_WINDOWS or IS_MACOS):
             lib_file_path = find_library_location("libtorchbind_test.so")
-            torch.ops.load_library(str(lib_file_path))
+            if lib_file_path.exists():
+                torch.ops.load_library(str(lib_file_path))
+                self._torchbind_test_loaded = True
 
     def tearDown(self):
         super().tearDown()
@@ -873,7 +876,7 @@ class TestFX(JitTestCase):
         self.checkGraphModule(m, (a, b))
 
     def test_native_callable(self):
-        if IS_FBCODE or IS_WINDOWS or IS_MACOS:
+        if IS_FBCODE or IS_WINDOWS or IS_MACOS or not self._torchbind_test_loaded:
             raise unittest.SkipTest("non-portable load_library call used in test")
         # This test exercises the case where we use FX to translate from Python
         # code to some native callable object
@@ -3067,7 +3070,7 @@ class TestFX(JitTestCase):
             node.__update_args_kwargs((), {})
 
     def test_torchbind_class_attribute_in_fx(self):
-        if IS_FBCODE or IS_WINDOWS or IS_MACOS:
+        if IS_FBCODE or IS_WINDOWS or IS_MACOS or not self._torchbind_test_loaded:
             self.skipTest(
                 "torch.classes._TorchScriptTesting._StackString is registered, skipping"
             )
@@ -3084,7 +3087,7 @@ class TestFX(JitTestCase):
         self.checkGraphModule(m, ())
 
     def test_torchbind_class_attribute_in_fx_tensor_arg(self):
-        if IS_FBCODE or IS_WINDOWS or IS_MACOS:
+        if IS_FBCODE or IS_WINDOWS or IS_MACOS or not self._torchbind_test_loaded:
             self.skipTest(
                 "torch.classes._TorchScriptTesting._ReLUClass is registered, skipping"
             )

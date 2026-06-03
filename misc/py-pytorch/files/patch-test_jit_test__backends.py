--- test/jit/test_backends.py.orig	2026-04-18 20:22:08 UTC
+++ test/jit/test_backends.py
@@ -71,6 +71,8 @@ class JitBackendTestCase(JitTestCase):
     def setUp(self):
         super().setUp()
         lib_file_path = find_library_location("libjitbackend_test.so")
+        if not lib_file_path.exists():
+            raise unittest.SkipTest(f"libjitbackend_test.so not found (C++ test library)")
         torch.ops.load_library(str(lib_file_path))
         # Subclasses are expected to set up three variables in their setUp methods:
         # module - a regular, Python version of the module being tested
@@ -514,6 +516,8 @@ class JitBackendTestCaseWithCompiler(JitTestCase):
     def setUp(self):
         super().setUp()
         lib_file_path = find_library_location("libbackend_with_compiler.so")
+        if not lib_file_path.exists():
+            raise unittest.SkipTest(f"libbackend_with_compiler.so not found (C++ test library)")
         torch.ops.load_library(str(lib_file_path))
         # Subclasses are expected to set up four variables in their setUp methods:
         # module - a regular, Python version of the module being tested

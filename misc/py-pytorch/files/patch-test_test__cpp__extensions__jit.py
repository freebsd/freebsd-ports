--- test/test_cpp_extensions_jit.py.orig	2026-10-28 18:13:31 UTC
+++ test/test_cpp_extensions_jit.py
@@ -562,7 +562,8 @@ with tempfile.TemporaryDirectory() as build_directory:
         self.assertEqual(module.f(), 789)
 
     @unittest.skipIf(
-        "utf" not in locale.getlocale()[1].lower(), "Only test in UTF-8 locale"
+        not (locale.getlocale()[1] and "utf" in locale.getlocale()[1].lower()),
+        "Only test in UTF-8 locale",
     )
     def test_load_with_non_platform_default_encoding(self):
         # Assume the code is saved in UTF-8, but the locale is set to a different encoding.

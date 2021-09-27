--- tests/test_popen_spawn.py.orig	2020-01-17 17:08:15 UTC
+++ tests/test_popen_spawn.py
@@ -110,13 +110,13 @@ class ExpectTestCase (PexpectTestCase.PexpectTestCase)
 
     def test_bad_arg(self):
         p = PopenSpawn('cat')
-        with self.assertRaisesRegexp(TypeError, '.*must be one of'):
+        with self.assertRaisesRegex(TypeError, '.*must be one of'):
             p.expect(1)
-        with self.assertRaisesRegexp(TypeError, '.*must be one of'):
+        with self.assertRaisesRegex(TypeError, '.*must be one of'):
             p.expect([1, b'2'])
-        with self.assertRaisesRegexp(TypeError, '.*must be one of'):
+        with self.assertRaisesRegex(TypeError, '.*must be one of'):
             p.expect_exact(1)
-        with self.assertRaisesRegexp(TypeError, '.*must be one of'):
+        with self.assertRaisesRegex(TypeError, '.*must be one of'):
             p.expect_exact([1, b'2'])
 
     def test_timeout_none(self):

--- tests/test_expect.py.orig	2021-09-22 12:21:58 UTC
+++ tests/test_expect.py
@@ -411,7 +411,7 @@ class ExpectTestCase (PexpectTestCase.PexpectTestCase):
     def test_before_across_chunks(self):
         # https://github.com/pexpect/pexpect/issues/478
         child = pexpect.spawn(
-            '''/bin/bash -c "openssl rand -base64 {} 2>/dev/null | head -500 | nl --number-format=rz --number-width=5 2>&1 ; echo 'PATTERN!!!'"'''.format(1024 * 1024 * 2),
+            '''/bin/sh -c "openssl rand -base64 {} 2>/dev/null | head -500 | nl -n rz -w 5 2>&1 ; echo 'PATTERN!!!'"'''.format(1024 * 1024 * 2),
             searchwindowsize=128
         )
         child.expect(['PATTERN'])
@@ -456,7 +456,7 @@ class ExpectTestCase (PexpectTestCase.PexpectTestCase):
         child = pexpect.spawn('cat', echo=False)
         child.sendline('BEGIN')
         for i in range(100):
-            child.sendline('foo' * 100)
+            child.sendline('foo' * 10)
         e = child.expect([b'xyzzy', pexpect.TIMEOUT],
                          searchwindowsize=10, timeout=0.001)
         self.assertEqual(e, 1)
@@ -473,7 +473,7 @@ class ExpectTestCase (PexpectTestCase.PexpectTestCase):
         child = pexpect.spawn('cat', echo=False)
         child.sendline('BEGIN')
         for i in range(100):
-            child.sendline('foo' * 100)
+            child.sendline('foo' * 10)
         e = child.expect([b'xyzzy', pexpect.TIMEOUT],
                          searchwindowsize=10, timeout=0.5)
         self.assertEqual(e, 1)
@@ -569,13 +569,13 @@ class ExpectTestCase (PexpectTestCase.PexpectTestCase)
 
     def test_bad_arg(self):
         p = pexpect.spawn('cat')
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

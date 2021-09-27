--- tests/PexpectTestCase.py.orig	2020-01-17 17:08:15 UTC
+++ tests/PexpectTestCase.py
@@ -97,7 +97,7 @@ class PexpectTestCase(unittest.TestCase):
                 raise AssertionError("%s was not raised" % excClass)
 
         @contextlib.contextmanager
-        def assertRaisesRegexp(self, excClass, pattern):
+        def assertRaisesRegex(self, excClass, pattern):
             import re
             try:
                 yield

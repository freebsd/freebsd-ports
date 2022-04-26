--- lib/Crypto/SelfTest/Util/test_number.py.orig	2013-10-14 21:38:10 UTC
+++ lib/Crypto/SelfTest/Util/test_number.py
@@ -276,6 +276,11 @@ class MiscTests(unittest.TestCase):
         self.assertEqual(number.size(0xa2ba40),8*3)
         self.assertEqual(number.size(0xa2ba40ee07e3b2bd2f02ce227f36a195024486e49c19cb41bbbdfbba98b22b0e577c2eeaffa20d883a76e65e394c69d4b3c05a1e8fadda27edb2a42bc000fe888b9b32c22d15add0cd76b3e7936e19955b220dd17d4ea904b1ec102b2e4de7751222aa99151024c7cb41cc5ea21d00eeb41f7c800834d2c6e06bce3bce7ea9a5L), 1024)
 
+class FastmathTests(unittest.TestCase):
+    def setUp(self):
+        global number
+        from Crypto.Util import number
+
     def test_negative_number_roundtrip_mpzToLongObj_longObjToMPZ(self):
         """Test that mpzToLongObj and longObjToMPZ (internal functions) roundtrip negative numbers correctly."""
         n = -100000000000000000000000000000000000L
@@ -286,7 +291,21 @@ class MiscTests(unittest.TestCase):
 
 def get_tests(config={}):
     from Crypto.SelfTest.st_common import list_test_cases
-    return list_test_cases(MiscTests)
+    tests = list_test_cases(MiscTests)
+    try:
+        from Crypto.PublicKey import _fastmath
+        tests += list_test_cases(FastmathTests)
+    except ImportError:
+        from distutils.sysconfig import get_config_var
+        import inspect, os.path
+        _fm_path = os.path.normpath(os.path.dirname(os.path.abspath(
+            inspect.getfile(inspect.currentframe())))
+            +"/../../PublicKey/_fastmath"+get_config_var("SO"))
+        if os.path.exists(_fm_path):
+            raise ImportError("While the _fastmath module exists, importing "+
+                "it failed. This may point to the gmp or mpir shared library "+
+                "not being in the path. _fastmath was found at "+_fm_path)
+    return tests
 
 if __name__ == '__main__':
     suite = lambda: unittest.TestSuite(get_tests())

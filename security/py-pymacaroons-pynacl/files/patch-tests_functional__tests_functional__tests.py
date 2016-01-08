--- tests/functional_tests/functional_tests.py.orig	2016-01-04 04:05:59 UTC
+++ tests/functional_tests/functional_tests.py
@@ -3,6 +3,7 @@ import json
 
 from mock import *
 from nose.tools import *
+from unittest import skipUnless
 
 import nacl.bindings
 
@@ -11,6 +12,11 @@ from pymacaroons.serializers import *
 from pymacaroons.exceptions import *
 from pymacaroons.utils import *
 
+# A test desires libnacl, but we don't need it.
+try:
+    import libnacl
+except:
+    pass
 
 ZERO_NONCE = truncate_or_pad(
     b'\0', size=nacl.bindings.crypto_secretbox_NONCEBYTES)
@@ -297,6 +303,7 @@ never use the same secret twice',
         )
         assert_true(verified)
 
+    @skipUnless('libnacl' in globals(), 'libnacl imported already')
     @patch('libnacl.secret.libnacl.utils.rand_nonce')
     def test_inspect(self, rand_nonce):
         # use a fixed nonce to ensure the same signature

--- w3af/plugins/tests/grep/test_clamav.py.orig	2015-04-07 15:04:48 UTC
+++ w3af/plugins/tests/grep/test_clamav.py
@@ -21,7 +21,7 @@ Foundation, Inc., 51 Franklin St, Fifth 
 """
 import unittest
 import time
-import clamd
+import pyclamd
 
 from nose.plugins.attrib import attr
 from itertools import repeat
@@ -69,7 +69,7 @@ class TestClamAV(unittest.TestCase):
     @patch('w3af.plugins.grep.code_disclosure.is_404', side_effect=repeat(False))
     @need_clamav
     def test_clamav_eicar(self, *args):
-        body = clamd.EICAR
+        body = pyclamd.EICAR
         url = URL('http://www.w3af.com/')
         headers = Headers([('content-type', 'text/html')])
         response = HTTPResponse(200, body, headers, url, url, _id=1)
@@ -151,7 +151,7 @@ class TestClamAV(unittest.TestCase):
 
     @patch('w3af.plugins.grep.code_disclosure.is_404', side_effect=repeat(False))
     def test_no_clamav_eicar(self, *args):
-        body = clamd.EICAR
+        body = pyclamd.EICAR
         url = URL('http://www.w3af.com/')
         headers = Headers([('content-type', 'text/html')])
         response = HTTPResponse(200, body, headers, url, url, _id=1)
@@ -213,4 +213,4 @@ class TestClamAVScan(PluginTest):
         for finding in findings:
             self.assertIn(finding.get_url().get_file_name(), EXPECTED_FILES)
             self.assertEqual(finding.get_name(), 'Malware identified')
-            self.assertIn('ClamAV identified malware', finding.get_desc())
\ No newline at end of file
+            self.assertIn('ClamAV identified malware', finding.get_desc())

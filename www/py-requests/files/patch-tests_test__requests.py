# https://github.com/psf/requests/issues/5530
--- tests/test_requests.py.orig	2020-12-16 17:43:25 UTC
+++ tests/test_requests.py
@@ -838,7 +838,7 @@ class TestRequests:
     def test_https_warnings(self, httpbin_secure, httpbin_ca_bundle):
         """warnings are emitted with requests.get"""
         if HAS_MODERN_SSL or HAS_PYOPENSSL:
-            warnings_expected = ('SubjectAltNameWarning', )
+            warnings_expected = ()
         else:
             warnings_expected = ('SNIMissingWarning',
                                  'InsecurePlatformWarning',

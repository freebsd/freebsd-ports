Make tests work with devel/py-pytest >= 4

Obtained from:
https://github.com/psf/requests/commit/0fe6653eabc3e0a4b8c48e374fb7ee83a3bf829b

--- tests/test_utils.py.orig	2019-05-16 14:18:16 UTC
+++ tests/test_utils.py
@@ -33,7 +33,8 @@ class TestSuperLen:
         'stream, value', (
             (StringIO.StringIO, 'Test'),
             (BytesIO, b'Test'),
-            pytest.mark.skipif('cStringIO is None')((cStringIO, 'Test')),
+            pytest.param(cStringIO, 'Test',
+                        marks=pytest.mark.skipif('cStringIO is None')),
         ))
     def test_io_streams(self, stream, value):
         """Ensures that we properly deal with different kinds of IO streams."""

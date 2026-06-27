-- Replace deprecated ndarray.tostring() with ndarray.tobytes() and
-- np.fromstring() with np.frombuffer() for NumPy 2.0+ compatibility.
-- Both were removed in NumPy 2.0.
--- klusta/tests/test_datasets.py.orig	2016-06-23 11:22:30 UTC
+++ klusta/tests/test_datasets.py
@@ -44,7 +44,7 @@ def mock_url():
 
 @yield_fixture
 def mock_url():
-    _add_mock_response(_URL, _DATA.tostring())
+    _add_mock_response(_URL, _DATA.tobytes())
     _add_mock_response(_URL + '.md5', _CHECKSUM + '  ' + op.basename(_URL))
     yield
     responses.reset()
@@ -52,7 +52,7 @@ def mock_urls(request):
 
 @yield_fixture(params=product((True, False), repeat=4))
 def mock_urls(request):
-    data = _DATA.tostring()
+    data = _DATA.tobytes()
     checksum = _CHECKSUM
     url_data = _URL
     url_checksum = _URL + '.md5'
@@ -84,7 +84,7 @@ def _check(data):
 
 
 def _check(data):
-    ae(np.fromstring(data, np.float32), _DATA)
+    ae(np.frombuffer(data, np.float32), _DATA)
 
 
 #------------------------------------------------------------------------------
@@ -122,7 +122,7 @@ def test_download_already_exists_valid(tempdir, mock_u
     path = op.join(tempdir, 'test')
     # Create valid file.
     with open(path, 'ab') as f:
-        f.write(_DATA.tostring())
+        f.write(_DATA.tobytes())
     _check(_dl(path))
 
 
@@ -154,13 +154,13 @@ def test_download_sample_data(tempdir):
     name = 'hybrid_10sec.dat'
     url = _BASE_URL['cortexlab'] + name
 
-    _add_mock_response(url, _DATA.tostring())
+    _add_mock_response(url, _DATA.tobytes())
     _add_mock_response(url + '.md5', _CHECKSUM)
 
     download_sample_data(name, tempdir)
     with open(op.join(tempdir, name), 'rb') as f:
         data = f.read()
-    ae(np.fromstring(data, np.float32), _DATA)
+    ae(np.frombuffer(data, np.float32), _DATA)
 
     responses.reset()
 
@@ -171,7 +171,7 @@ def test_dat_file(tempdir):
                              low=-100, high=100).astype(np.int16)
     fn = 'test-4ch-1s.dat'
     _add_mock_response(_BASE_URL['github'] + 'test/' + fn,
-                       data.tostring())
+                       data.tobytes())
 
     path = download_test_data(fn, tempdir)
     with open(path, 'rb') as f:

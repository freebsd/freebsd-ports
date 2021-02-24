--- test_httpbin.py.orig	2018-05-08 11:41:03 UTC
+++ test_httpbin.py
@@ -144,7 +144,9 @@ class HttpbinTestCase(unittest.TestCase):
         data = json.loads(response.data.decode('utf-8'))
         self.assertEqual(data['args'], {})
         self.assertEqual(data['headers']['Host'], 'localhost')
-        self.assertEqual(data['headers']['Content-Length'], '0')
+        # Newest Werkzeug versions omit Content-Length if '0'; see
+        # https://github.com/postmanlabs/httpbin/pull/555/files
+        self.assertEqual(data['headers'].get('Content-Length', '0'), '0')
         self.assertEqual(data['headers']['User-Agent'], 'test')
         # self.assertEqual(data['origin'], None)
         self.assertEqual(data['url'], 'http://localhost/get')
@@ -158,7 +160,9 @@ class HttpbinTestCase(unittest.TestCase):
         data = json.loads(response.data.decode('utf-8'))
         self.assertEqual(data['args'], {})
         self.assertEqual(data['headers']['Host'], 'localhost')
-        self.assertEqual(data['headers']['Content-Length'], '0')
+        # Newest Werkzeug versions omit Content-Length if '0'; see
+        # https://github.com/postmanlabs/httpbin/pull/555/files
+        self.assertEqual(data['headers'].get('Content-Length', '0'), '0')
         self.assertEqual(data['url'], 'http://localhost/anything/foo/bar')
         self.assertEqual(data['method'], 'GET')
         self.assertTrue(response.data.endswith(b'\n'))

--- supervisor/tests/test_options.py.orig	2018-02-15 21:31:47 UTC
+++ supervisor/tests/test_options.py
@@ -160,12 +160,9 @@ class OptionTests(unittest.TestCase):
 
     def test_searchpaths(self):
         options = self._makeOptions()
-        self.assertEqual(len(options.searchpaths), 6)
-        self.assertEqual(options.searchpaths[-4:], [
-            'supervisord.conf',
-            'etc/supervisord.conf',
-            '/etc/supervisord.conf',
-            '/etc/supervisor/supervisord.conf',
+        self.assertEqual(len(options.searchpaths), 1)
+        self.assertEqual(options.searchpaths[-1:], [
+            '%%PREFIX%%/etc/supervisord.conf',
             ])
 
     def test_options_and_args_order(self):

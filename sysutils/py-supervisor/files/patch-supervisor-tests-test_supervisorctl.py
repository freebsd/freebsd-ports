--- supervisor/tests/test_supervisorctl.py.orig	2016-06-08 17:08:09.404989000 +0300
+++ supervisor/tests/test_supervisorctl.py	2016-06-08 17:08:32.361939000 +0300
@@ -1562,23 +1562,23 @@ class TestDefaultControllerPlugin(unitte
         val = plugin.ctl.stdout.getvalue()
         self.assertTrue(val.startswith('Error: bad argument wrong'), val)
 
-    def _dont_test_maintail_dashf(self):
+#    def _dont_test_maintail_dashf(self):
         # https://github.com/Supervisor/supervisor/issues/285
         # TODO: Refactor so we can test more of maintail -f than just a
         # connect error, and fix this test so it passes on FreeBSD.
-        plugin = self._makeOne()
-        plugin.listener = DummyListener()
-        result = plugin.do_maintail('-f')
-        self.assertEqual(result, None)
-        errors = plugin.listener.errors
-        self.assertEqual(len(errors), 1)
-        error = errors[0]
-        self.assertEqual(plugin.listener.closed,
-                         'http://localhost:65532/mainlogtail')
-        self.assertEqual(error[0],
-                         'http://localhost:65532/mainlogtail')
-        for msg in ('Cannot connect', 'socket.error'):
-            self.assertTrue(msg in error[1])
+#        plugin = self._makeOne()
+#        plugin.listener = DummyListener()
+#        result = plugin.do_maintail('-f')
+#        self.assertEqual(result, None)
+#        errors = plugin.listener.errors
+#        self.assertEqual(len(errors), 1)
+#        error = errors[0]
+#        self.assertEqual(plugin.listener.closed,
+#                         'http://localhost:65532/mainlogtail')
+#        self.assertEqual(error[0],
+#                         'http://localhost:65532/mainlogtail')
+#        for msg in ('Cannot connect', 'socket.error'):
+#            self.assertTrue(msg in error[1])
 
     def test_maintail_bad_modifier(self):
         plugin = self._makeOne()

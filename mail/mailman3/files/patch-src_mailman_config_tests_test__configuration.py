--- src/mailman/config/tests/test_configuration.py.orig	2018-01-08 11:00:18 UTC
+++ src/mailman/config/tests/test_configuration.py
@@ -88,12 +88,12 @@ class TestExternal(unittest.TestCase):
         filename = resource_filename('mailman.config', 'postfix.cfg')
         parser = external_configuration(filename)
         self.assertEqual(parser.get('postfix', 'postmap_command'),
-                         '/usr/sbin/postmap')
+                         '/usr/local/sbin/postmap')
 
     def test_external_configuration_by_path(self):
         parser = external_configuration('python:mailman.config.postfix')
         self.assertEqual(parser.get('postfix', 'postmap_command'),
-                         '/usr/sbin/postmap')
+                         '/usr/local/sbin/postmap')
 
     def test_missing_configuration_file(self):
         with self.assertRaises(MissingConfigurationFileError) as cm:

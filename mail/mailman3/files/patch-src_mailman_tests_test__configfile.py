--- src/mailman/tests/test_configfile.py.orig	2017-11-16 05:50:21 UTC
+++ src/mailman/tests/test_configfile.py
@@ -161,8 +161,8 @@ class TestConfigFileSearchWithChroot(TestConfigFileBas
                 self.assertEqual(search_for_configuration_file(), config_file)
 
     def test_etc_file(self):
-        # Test /etc/mailman.cfg
-        fake_etc = '/etc'
+        # Test /usr/local/etc/mailman.cfg
+        fake_etc = '/usr/local/etc'
         fake_testdir = self._make_fake(fake_etc)
         config_file = os.path.join(fake_etc, 'mailman.cfg')
         with fakedirs(fake_testdir):
@@ -172,8 +172,8 @@ class TestConfigFileSearchWithChroot(TestConfigFileBas
             self.assertEqual(search_for_configuration_file(), config_file)
 
     def test_etc_mailman3_file(self):
-        # Test /etc/mailman3/mailman.cfg
-        fake_etc = '/etc/mailman3'
+        # Test /usr/local/etc/mailman3/mailman.cfg
+        fake_etc = '/usr/local/etc/mailman3'
         fake_testdir = self._make_fake(fake_etc)
         config_file = os.path.join(fake_etc, 'mailman.cfg')
         with fakedirs(fake_testdir):

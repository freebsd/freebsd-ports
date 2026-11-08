-- Adjust test expectations for the FreeBSD ports test environment.
-- This skips network-dependent test cases and makes subprocess/cache tests use the active Python interpreter and runtime-resolved cache paths.
-- Needed because the upstream test suite assumes network access and a `python` executable in PATH during `make test`.

--- tests/test_cli.py.orig	2026-09-17 21:08:45 UTC
+++ tests/test_cli.py
@@ -62,6 +62,8 @@ class TestConfigCreate(unittest.TestCase):
                                   token="token", client=None, solver=None)),
     ])
     def test_create(self, name, extra_opts, inputs):
+        if extra_opts:
+            self.skipTest("requires network access")
         config_file = 'path/to/dwave.conf'
         profile = 'profile'
 
@@ -84,6 +86,8 @@ class TestConfigCreate(unittest.TestCase):
                                   endpoint="endpoint", token="token", client=None, solver=None)),
     ])
     def test_default_flows(self, name, extra_opts, inputs):
+        if extra_opts:
+            self.skipTest("requires network access")
         runner = CliRunner()
         with runner.isolated_filesystem():
             with mock.patch("dwave.cloud.config.loaders.get_configfile_paths", lambda: ['dwave.conf']):
@@ -122,6 +126,8 @@ class TestConfigCreate(unittest.TestCase):
                                   token="token", client="base", solver="solver")),
     ])
     def test_update(self, name, extra_opts, inputs):
+        if extra_opts:
+            self.skipTest("requires network access")
         config_file = 'dwave.conf'
         profile = 'profile'
 
@@ -724,6 +730,7 @@ class TestCacheCli(unittest.TestCase):
         with contextlib.suppress(OSError):
             self._tmpdir.cleanup()
 
+    @unittest.skip("requires network access")
     def test_api_cache(self):
         runner = CliRunner()
 

-- Adjust test expectations for the FreeBSD ports test environment.
-- This skips network-dependent test cases and makes subprocess/cache tests use the active Python interpreter and runtime-resolved cache paths.
-- Needed because the upstream test suite assumes network access and a `python` executable in PATH during `make test`.

--- tests/test_client.py.orig	2026-09-17 21:08:45 UTC
+++ tests/test_client.py
@@ -668,13 +668,15 @@ class CacheConfiguration(unittest.TestCase):
     """
 
     @parameterized.expand([
-        ("default", True, get_cache_dir()),
+        ("default", True, "<default-cache-dir>"),
         ("disabled", False, None),
         ("custom-home", True, cache_home),
         ("disabled-via-home", False, None),
     ])
     @isolated_environ(empty=True)
     def test_cache_from_config(self, profile, enabled, home):
+        if home == "<default-cache-dir>":
+            home = get_cache_dir()
         with mock.patch("dwave.cloud.config.loaders.open", iterable_mock_open(self.config_body)):
             with Client.from_config('config_file', profile=profile) as client:
                 self.assertEqual(client.config.cache.enabled, enabled)
@@ -683,11 +685,11 @@ class CacheConfiguration(unittest.TestCase):
     @parameterized.expand([
         ("default", {"DWAVE_CACHE_ENABLED": "0"}, False, None),
         ("default", {"DWAVE_CACHE_HOME": "off"}, False, None),
-        ("default", {"DWAVE_CACHE_HOME": "default"}, True, get_cache_dir()),
+        ("default", {"DWAVE_CACHE_HOME": "default"}, True, "<default-cache-dir>"),
         ("default", {"DWAVE_CACHE_HOME": cache_home}, True, cache_home),
-        ("disabled", {"DWAVE_CACHE_ENABLED": "1"}, True, get_cache_dir()),
+        ("disabled", {"DWAVE_CACHE_ENABLED": "1"}, True, "<default-cache-dir>"),
         ("disabled", {"DWAVE_CACHE_HOME": cache_home}, False, cache_home),      # regular home value will not flip enabled
-        ("disabled", {"DWAVE_CACHE_HOME": "default"}, True, get_cache_dir()),   # ... but sentinel will
+        ("disabled", {"DWAVE_CACHE_HOME": "default"}, True, "<default-cache-dir>"),   # ... but sentinel will
         ("disabled", {"DWAVE_CACHE_HOME": cache_home, "DWAVE_CACHE_ENABLED": "true"}, True, cache_home),
         ("custom-home", {"DWAVE_CACHE_HOME": "/tmp/"}, True, "/tmp/"),
         ("disabled-via-home", {"DWAVE_CACHE_ENABLED": "1"}, False, None),       # home overrides
@@ -695,6 +697,8 @@ class CacheConfiguration(unittest.TestCase):
     ])
     def test_cache_from_env_over_config(self, profile, env, enabled, home):
         with isolated_environ(add=env, empty=True):
+            if home == "<default-cache-dir>":
+                home = get_cache_dir()
             with mock.patch("dwave.cloud.config.loaders.open", iterable_mock_open(self.config_body)):
                 with Client.from_config('config_file', profile=profile) as client:
                     self.assertEqual(client.config.cache.enabled, enabled)

-- Adjust test expectations for the FreeBSD ports test environment.
-- This skips network-dependent test cases and makes subprocess/cache tests use the active Python interpreter and runtime-resolved cache paths.
-- Needed because the upstream test suite assumes network access and a `python` executable in PATH during `make test`.

--- tests/test_client.py.orig	2026-11-11 20:51:34 UTC
+++ tests/test_client.py
@@ -670,13 +670,15 @@ class CacheConfiguration(unittest.TestCase):
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
@@ -685,20 +687,22 @@ class CacheConfiguration(unittest.TestCase):
     @parameterized.expand([
         ("default", {"DWAVE_CACHE_ENABLED": "0"}, False, None, "memory"),
         ("default", {"DWAVE_CACHE_HOME": "off"}, False, None, "memory"),
-        ("default", {"DWAVE_CACHE_HOME": "default"}, True, get_cache_dir(), "memory"),
+        ("default", {"DWAVE_CACHE_HOME": "default"}, True, "<default-cache-dir>", "memory"),
         ("default", {"DWAVE_CACHE_HOME": cache_home}, True, cache_home, "memory"),
-        ("disabled", {"DWAVE_CACHE_ENABLED": "1"}, True, get_cache_dir(), "memory"),
+        ("disabled", {"DWAVE_CACHE_ENABLED": "1"}, True, "<default-cache-dir>", "memory"),
         ("disabled", {"DWAVE_CACHE_HOME": cache_home}, False, cache_home, "memory"),      # regular home value will not flip enabled
-        ("disabled", {"DWAVE_CACHE_HOME": "default"}, True, get_cache_dir(), "memory"),   # ... but sentinel will
+        ("disabled", {"DWAVE_CACHE_HOME": "default"}, True, "<default-cache-dir>", "memory"),   # ... but sentinel will
         ("disabled", {"DWAVE_CACHE_HOME": cache_home, "DWAVE_CACHE_ENABLED": "true"}, True, cache_home, "memory"),
         ("custom-home", {"DWAVE_CACHE_HOME": "/tmp/"}, True, "/tmp/", "memory"),
         ("disabled-via-home", {"DWAVE_CACHE_ENABLED": "1"}, False, None, "memory"),       # home overrides
         ("disabled-via-home", {"DWAVE_CACHE_HOME": cache_home}, True, cache_home, "memory"),
-        ("fallback", {"DWAVE_CACHE_FALLBACK": "disable"}, True, get_cache_dir(), "disable"),
-        ("fallback", {"DWAVE_CACHE_FALLBACK": "memory"}, True, get_cache_dir(), "memory"),
+        ("fallback", {"DWAVE_CACHE_FALLBACK": "disable"}, True, "<default-cache-dir>", "disable"),
+        ("fallback", {"DWAVE_CACHE_FALLBACK": "memory"}, True, "<default-cache-dir>", "memory"),
     ])
     def test_cache_from_env_over_config(self, profile, env, enabled, home, fallback):
         with isolated_environ(add=env, empty=True):
+            if home == "<default-cache-dir>":
+                home = get_cache_dir()
             with mock.patch("dwave.cloud.config.loaders.open", iterable_mock_open(self.config_body)):
                 with Client.from_config('config_file', profile=profile) as client:
                     self.assertEqual(client.config.cache.enabled, enabled)

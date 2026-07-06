-- Fix cmake BOOL value parsing to handle "true" in addition to "ON", "YES", "1".
-- CMake stores BOOL values detected from libraries (e.g. find_package) as "true"
-- rather than "ON", causing tests to fail when features like JPEG/PNG/GZIP/FFMPEG
-- are detected and enabled but not recognized by the test's cmake cache parser.

--- unittest/python/python-capabilities.py.orig	2026-04-16 02:16:46 UTC
+++ unittest/python/python-capabilities.py
@@ -23,7 +23,7 @@ class PythonCapabilities(unittest.TestCase):
                     if len(parts) > 1:
                         value = parts[1]
                         if value_type == "BOOL":
-                            value = (value.upper() == "ON") or (value.upper() == "YES") or (value == "1")
+                            value = (value.upper() in ("ON", "YES", "TRUE")) or (value == "1")
                     else:
                         value = None
                     self.cmake_cache[key] = value

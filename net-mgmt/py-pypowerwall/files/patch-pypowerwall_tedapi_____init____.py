--- pypowerwall/tedapi/__init__.py.orig	2026-02-22 08:00:17 UTC
+++ pypowerwall/tedapi/__init__.py
@@ -304,6 +304,8 @@ class TEDAPI:
                 except json.JSONDecodeError as e:
                     log.error(f"Error Decoding JSON: {e}")
                     data = {}
+                if 'battery_blocks' not in data:
+                    data["battery_blocks"] = []
                 log.debug(f"Configuration: {data}")
                 self.pwcachetime["config"] = time.time()
                 self.pwcache["config"] = data

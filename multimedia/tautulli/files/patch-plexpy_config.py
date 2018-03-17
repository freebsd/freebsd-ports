--- plexpy/config.py.orig	2018-03-17 14:16:52 UTC
+++ plexpy/config.py
@@ -111,7 +111,7 @@ _CONFIG_DEFINITIONS = {
     'CACHE_DIR': (str, 'General', ''),
     'CACHE_IMAGES': (int, 'General', 1),
     'CACHE_SIZEMB': (int, 'Advanced', 32),
-    'CHECK_GITHUB': (int, 'General', 1),
+    'CHECK_GITHUB': (int, 'General', 0),
     'CHECK_GITHUB_INTERVAL': (int, 'General', 360),
     'CHECK_GITHUB_ON_STARTUP': (int, 'General', 1),
     'CLEANUP_FILES': (int, 'General', 0),

--- plexpy/config.py.orig	2021-10-27 10:01:59 UTC
+++ plexpy/config.py
@@ -89,7 +89,7 @@ _CONFIG_DEFINITIONS = {
     'CACHE_IMAGES': (int, 'General', 1),
     'CACHE_SIZEMB': (int, 'Advanced', 32),
     'CHECK_DOCKER_MOUNT': (int, 'Advanced', 1),
-    'CHECK_GITHUB': (int, 'General', 1),
+    'CHECK_GITHUB': (int, 'General', 0),
     'CHECK_GITHUB_INTERVAL': (int, 'General', 360),
     'CHECK_GITHUB_ON_STARTUP': (int, 'General', 1),
     'CHECK_GITHUB_CACHE_SECONDS': (int, 'Advanced', 3600),

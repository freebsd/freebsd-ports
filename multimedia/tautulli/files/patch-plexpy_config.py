--- plexpy/config.py.orig	2022-04-22 21:51:37.128263000 -0600
+++ plexpy/config.py	    2022-04-22 21:51:43.034517000 -0600
@@ -90,7 +90,7 @@
     'CACHE_IMAGES': (int, 'General', 1),
     'CACHE_SIZEMB': (int, 'Advanced', 32),
     'CHECK_DOCKER_MOUNT': (int, 'Advanced', 1),
-    'CHECK_GITHUB': (int, 'General', 1),
+    'CHECK_GITHUB': (int, 'General', 0),
     'CHECK_GITHUB_INTERVAL': (int, 'General', 6),
     'CHECK_GITHUB_ON_STARTUP': (int, 'General', 1),
     'CHECK_GITHUB_CACHE_SECONDS': (int, 'Advanced', 3600),

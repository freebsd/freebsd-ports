--- plexpy/config.py.orig	2017-05-15 14:05:14 UTC
+++ plexpy/config.py
@@ -107,7 +107,7 @@ _CONFIG_DEFINITIONS = {
     'CACHE_DIR': (str, 'General', ''),
     'CACHE_IMAGES': (int, 'General', 1),
     'CACHE_SIZEMB': (int, 'Advanced', 32),
-    'CHECK_GITHUB': (int, 'General', 1),
+    'CHECK_GITHUB': (int, 'General', 0),
     'CHECK_GITHUB_INTERVAL': (int, 'General', 360),
     'CHECK_GITHUB_ON_STARTUP': (int, 'General', 1),
     'CLEANUP_FILES': (int, 'General', 0),
@@ -812,4 +812,4 @@ class Config(object):
         if self.CONFIG_VERSION == '6':
             if self.GIT_USER.lower() == 'drzoidberg33':
                 self.GIT_USER = 'JonnyWong16'
-            self.CONFIG_VERSION = '7'
\ No newline at end of file
+            self.CONFIG_VERSION = '7'

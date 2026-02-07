--- setup.py.orig	2025-11-17 15:32:57 UTC
+++ setup.py
@@ -30,7 +30,7 @@ EXTRAS_REQUIRE = {
     'requests': [
         'requests >= 2.18.0, < 3.0.0',
     ],
-    'aiohttp': ['aiohttp >= 3.6.2, < 4.0.0', 'google-auth >= 1.22.0, < 2.0.0']
+    'aiohttp': ['aiohttp >= 3.6.2, < 4.0.0', 'google-auth >= 1.22.0, < 3.0.0']
 }
 
 setuptools.setup(

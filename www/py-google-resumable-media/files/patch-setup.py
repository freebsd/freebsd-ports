--- setup.py.orig	2023-09-06 18:09:24 UTC
+++ setup.py
@@ -30,7 +30,7 @@ EXTRAS_REQUIRE = {
     'requests': [
         'requests >= 2.18.0, < 3.0.0dev',
     ],
-    'aiohttp': ['aiohttp >= 3.6.2, < 4.0.0dev', 'google-auth >= 1.22.0, < 2.0dev']
+    'aiohttp': ['aiohttp >= 3.6.2, < 4.0.0dev', 'google-auth >= 1.22.0, < 3.0dev']
 }
 
 setuptools.setup(

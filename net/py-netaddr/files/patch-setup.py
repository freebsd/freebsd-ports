--- setup.py.orig	2017-04-21 11:40:00 UTC
+++ setup.py
@@ -62,11 +62,6 @@ def main():
         scripts          = release.scripts,
         url              = release.url,
         version          = release.version,
-        options = {
-            'build_scripts': {
-                'executable': '/usr/bin/env python',
-            },
-        },
     )
 
     setup(**setup_options)

--- setup.py.orig	2017-01-11 23:42:52 UTC
+++ setup.py
@@ -174,11 +174,6 @@ def main():
         scripts=['netaddr/tools/netaddr'],
         url='https://github.com/drkjam/netaddr/',
         version=netaddr.__version__,
-        options={
-            'build_scripts': {
-                'executable': '/usr/bin/env python',
-            },
-        },
     )
 
     setup(**setup_options)

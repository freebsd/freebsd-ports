--- tools/gyp/pylib/gyp/common.py.orig	2012-05-30 10:04:06.000000000 +0300
+++ tools/gyp/pylib/gyp/common.py	2012-06-05 22:36:29.000000000 +0300
@@ -356,6 +356,7 @@
     'freebsd7': 'freebsd',
     'freebsd8': 'freebsd',
     'freebsd9': 'freebsd',
+    'freebsd10': 'freebsd',
   }
   flavor = flavors.get(sys.platform, 'linux')
   return params.get('flavor', flavor)

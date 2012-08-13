--- tools/gyp/pylib/gyp/common.py.orig	2012-07-11 21:33:14.908184100 -0400
+++ tools/gyp/pylib/gyp/common.py	2012-07-11 21:33:28.963202252 -0400
@@ -353,6 +353,8 @@
     'sunos5': 'solaris',
     'freebsd7': 'freebsd',
     'freebsd8': 'freebsd',
+    'freebsd9': 'freebsd',
+    'freebsd10': 'freebsd',
   }
   flavor = flavors.get(sys.platform, 'linux')
   return params.get('flavor', flavor)

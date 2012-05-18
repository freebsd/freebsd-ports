--- build/gyp/pylib/gyp/common.py.orig	2012-05-14 16:25:53.000000000 +0800
+++ build/gyp/pylib/gyp/common.py	2012-05-14 16:26:03.000000000 +0800
@@ -355,6 +355,8 @@ def GetFlavor(params):
     'sunos5': 'solaris',
     'freebsd7': 'freebsd',
     'freebsd8': 'freebsd',
+    'freebsd9': 'freebsd',
+    'freebsd10': 'freebsd',
   }
   flavor = flavors.get(sys.platform, 'linux')
   return params.get('flavor', flavor)

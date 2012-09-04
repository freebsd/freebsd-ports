--- tools/gyp/pylib/gyp/common.py.orig	2012-09-03 09:45:35.000000000 +0800
+++ tools/gyp/pylib/gyp/common.py	2012-09-03 09:46:36.000000000 +0800
@@ -366,7 +366,10 @@
     'freebsd8': 'freebsd',
     'freebsd9': 'freebsd',
   }
-  flavor = flavors.get(sys.platform, 'linux')
+  if 'freebsd' in sys.platform:
+      flavor = 'freebsd'
+  else:
+    flavor = flavors.get(sys.platform, 'linux')
   return params.get('flavor', flavor)
 
 

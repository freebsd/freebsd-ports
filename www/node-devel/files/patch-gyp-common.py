--- tools/gyp/pylib/gyp/common.py.orig	2012-02-02 03:37:12.000000000 +0800
+++ tools/gyp/pylib/gyp/common.py	2012-02-08 01:20:58.000000000 +0800
@@ -352,7 +352,10 @@
     'freebsd7': 'freebsd',
     'freebsd8': 'freebsd',
   }
-  flavor = flavors.get(sys.platform, 'linux')
+  if 'freebsd' in sys.platform:
+      flavor = 'freebsd'
+  else:
+    flavor = flavors.get(sys.platform, 'linux')
   return params.get('flavor', flavor)
 
 

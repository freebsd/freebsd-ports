--- salt/grains/core.py.orig	2015-01-24 14:54:03.078736129 -0700
+++ salt/grains/core.py	2015-01-24 14:53:12.000000000 -0700
@@ -1321,7 +1321,7 @@
     '''
     # Provides:
     #   path
-    return {'path': os.environ.get('PATH', '').strip()}
+    return {'path': os.environ.get('PATH', '').strip() + ':/usr/local/bin:/usr/local/sbin'}
 
 
 def pythonversion():

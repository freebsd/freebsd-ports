--- salt/grains/core.py.orig	2015-04-17 18:44:50 UTC
+++ salt/grains/core.py
@@ -1387,7 +1387,7 @@ def path():
     '''
     # Provides:
     #   path
-    return {'path': os.environ.get('PATH', '').strip()}
+    return {'path': os.environ.get('PATH', '').strip() + ':/usr/local/bin:/usr/local/sbin'}
 
 
 def pythonversion():

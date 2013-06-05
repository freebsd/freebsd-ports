--- ./salt/grains/core.py.orig	2013-05-29 00:22:30.000000000 -0600
+++ ./salt/grains/core.py	2013-05-31 10:09:03.273791365 -0600
@@ -791,7 +791,7 @@
     '''
     # Provides:
     #   path
-    return {'path': os.environ['PATH'].strip()}
+    return {'path': os.environ['PATH'].strip() + ':/usr/local/bin:/usr/local/sbin'}
 
 
 def pythonversion():

--- ./salt/grains/core.py.orig	2013-03-19 09:30:55.000000000 +0400
+++ ./salt/grains/core.py	2013-03-20 20:15:36.000000000 +0400
@@ -730,7 +730,7 @@
     '''
     # Provides:
     #   path
-    return {'path': os.environ['PATH'].strip()}
+    return {'path': os.environ['PATH'].strip() + ':/usr/local/bin:/usr/local/sbin'}
 
 
 def pythonversion():

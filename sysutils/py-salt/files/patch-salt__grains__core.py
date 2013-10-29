--- ./salt/grains/core.py.orig	2013-10-17 08:48:57.000000000 +0400
+++ ./salt/grains/core.py	2013-10-25 10:46:21.000000000 +0400
@@ -1059,7 +1059,7 @@
     '''
     # Provides:
     #   path
-    return {'path': os.environ['PATH'].strip()}
+    return {'path': os.environ['PATH'].strip() + ':/usr/local/bin:/usr/local/sbin'}
 
 
 def pythonversion():

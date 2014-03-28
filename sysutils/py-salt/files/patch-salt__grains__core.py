--- ./salt/grains/core.py.orig	2014-02-19 22:21:14.000000000 +0200
+++ ./salt/grains/core.py	2014-03-06 10:50:07.000000000 +0200
@@ -1133,7 +1133,7 @@
     # Provides:
     #   path
 
-    return {'path': os.environ['PATH'].strip()}
+    return {'path': os.environ['PATH'].strip() + ':/usr/local/bin:/usr/local/sbin'}
 
 
 def pythonversion():
